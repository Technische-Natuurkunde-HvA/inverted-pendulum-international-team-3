//for more information on the PID library: http://brettbeauregard.com/blog/2011/04/improving-the-beginners-pid-introduction/

#include <Wire.h>
#include <PID_v1.h>
#include <AS5600.h>

AS5600  as5600;  //create sensor object

unsigned long currentMs;  //current time variable
unsigned long lastMs;     // time of last measurement
const unsigned int FREE_RUN_PERIOD_MS = 5; //sampling period in milliseconds
double sig_angle_deg;  // angle measurement

// Motor control pins
const int motorPin1 = 10; // IN1
const int motorPin2 = 11; // IN2
const int enablePin = 9; // ENA (PWM pin for speed control)


double setpoint = 316.0; // Desired angle (vertical position)
double output = 0;

bool atBumper = false;

// PID parameters
double Kp = 20;
double Ki = 3;
double Kd = 2;
PID myPID(&sig_angle_deg, &output, &setpoint, Kp, Ki, Kd, DIRECT);

//void readAndPrintAngle();


void setup() {
  // Set motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  Wire.begin();     // Initialize I2C
  as5600.begin();   // Initialize sensor
  lastMs= millis();   // Initialize timing
  Serial.begin(9600);  // Initialize Serial Monitor
  delay(2000);
  Serial.print("Test: ");
  Serial.println();

  // Wait for "START" on the serial connection before beginning
  waitForStart();

  // Initialize PID controller (only after START received)
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(FREE_RUN_PERIOD_MS); // Set sample time in milliseconds
  myPID.SetOutputLimits(-205,205); // YOU CAN ADJUST THESE OUTPUT LIMITS IF YOU WISH
}

void loop() {
  // Read and print the angle from AS5600 at the sampling frequency
  currentMs = millis();
  if (currentMs - lastMs >= FREE_RUN_PERIOD_MS) {// periodic sampling

    readAndPrintAngle();

    myPID.Compute(); // Calculate PID output

    double compensatedOutput = output;

    // Set motor direction based on PID output
    if (output > 0) {
      compensatedOutput += 50; // Add a small constant to overcome motor deadzone

      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH); 
    } 

    else if (output < 0) {
      compensatedOutput -= 50; // Subtract a small constant to overcome motor deadzone

      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
    }

    else {

      compensatedOutput = 0;
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
    }

    analogWrite(enablePin, abs(compensatedOutput)); // Set motor speed

    // Print the angle to the Serial Monitor
    Serial.print(sig_angle_deg);
    Serial.print(",");
    // Print PID output for debugging
    Serial.println(compensatedOutput);
 
  }
}

void readAndPrintAngle() {
      lastMs = currentMs;
      sig_angle_deg = (float)as5600.readAngle()*0.0879; //0.0879=360/4096;  // degrees [0..360) 
}

// New helper: block until serial contains "START" (case-insensitive)
void waitForStart() {
  Serial.println("Waiting for 'START' on serial...");
  String buf = "";
  while (true) {
    while (Serial.available()) {
      char c = Serial.read();
      if (c == '\r' || c == '\n') {
        // ignore raw newlines, detection uses buffer content
        continue;
      }
      buf += c;
      // keep buffer limited
      if (buf.length() > 128) buf = buf.substring(buf.length() - 128);
      String t = buf;
      t.toUpperCase();
      if (t.indexOf("START") >= 0) {
        Serial.println("Received START. Beginning.");
        return;
      }
    }
    delay(10);
  }
}
