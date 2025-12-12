#include <Wire.h>
#include <AS5600.h>
AS5600  as5600;  //create sensor object
unsigned long currentMs;  //current time variable
unsigned long lastMs;     // time of last measurement
const unsigned int FREE_RUN_PERIOD_MS = 100; //sampling period
float sig_angle_deg;  // angle measurement

// Motor control pins
const int motorPin1 = 10; // IN1
const int motorPin2 = 11; // IN2
const int enablePin = 9; // ENA (PWM pin for speed control)

// RPM Calculation variables
const int encoderPin = 2; // use just one encoder pin for simplicity

volatile int pulseCount = 0;  // pulse counter
const int pulsesPerRevolution = 11; // pulses per rotation from each encoder wire

unsigned long lastRpmMs = 0;   // store last time measurement for RPM
double frequency = 0;         // measured frequency
const float ratio = 9.6;
double rpm = 0;

double output; 

void readAndPrintAngle();
void countPulse();

void setup() {
  // Set motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);

  output = 0 ;
  
  // Set encoder pin as input with pullup
  pinMode(encoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin), countPulse, RISING);
  
  Wire.begin();     // Initialize I2C
  as5600.begin();   // Initialize sensor
  lastMs = millis();   // Initialize timing
  lastRpmMs = millis(); // Initialize RPM timing
  Serial.begin(9600);  // Initialize Serial Monitor
  delay(2000);
  Serial.println("Test: Starting...");
}

void loop() {
  currentMs = millis();
  if (currentMs - lastMs >= FREE_RUN_PERIOD_MS) {// periodic sampling
    readAndPrintAngle();
  }
  
  // Van links naar rechts
  if (sig_angle_deg < 270 && output < 255){
    output = output + 10 ;
    delay(7);
  }
  else if (sig_angle_deg < 285 && sig_angle_deg > 250 && output > 0){
    output-- ;
    delay(2);
  }
  else if (sig_angle_deg > 290){
    output = 0 ;
  }

  analogWrite(enablePin, abs(output));

  // Frequency calculation every 0.5 seconds
  if (millis() - lastRpmMs >= 500) {
    noInterrupts();
    int count = pulseCount;
    pulseCount = 0;
    interrupts();

    // Calculate RPM properly
    if (count > 0) {
      frequency = count / 0.5; // Counts per second (Hz)
      rpm = (frequency * 60.0) / (pulsesPerRevolution * ratio);
    } else {
      rpm = 0;
    }
    
    lastRpmMs = millis();
  }
}

void countPulse() {
  pulseCount++;  // increment each pulse
}

void readAndPrintAngle() {
  lastMs = currentMs;
  sig_angle_deg = (float)as5600.readAngle() * 0.0879; //0.0879=360/4096;  // degrees [0..360)
  //Serial.print("Angle: ");
  Serial.print(sig_angle_deg);
  Serial.print(",");
  Serial.print(output);
  Serial.print(",");
  Serial.print(rpm);
  Serial.println();    
}