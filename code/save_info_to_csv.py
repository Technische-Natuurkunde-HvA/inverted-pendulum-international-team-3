# -------------------------------------------------------
# CONFIGURATIONS
# -------------------------------------------------------
import serial
import time


PORTA = "COM3"                 # <- Change to the correct port
BAUD = 9600
FICHEIRO = "data_serial.csv"
TEMPO_LEITURA = 20              # Seconds
# -------------------------------------------------------

try:
    ser = serial.Serial(PORTA, BAUD, timeout=1)
    time.sleep(2)  # Wait for the Arduino to restart
    print(f"Connected to {PORTA} at {BAUD} baud.")
    # Send START to the Arduino to trigger its script
    try:
        ser.write(b"START\n")
        ser.flush()
        print("Sent 'START' to Arduino. Waiting briefly for it to begin...")
        time.sleep(1)  # short pause for Arduino to process START
    except Exception as e:
        print(f"Error sending START: {e}")
except Exception as e:
    print(f"Error connecting to serial port: {e}")
    quit()

inicio = time.time()

with open(FICHEIRO, "w") as f:
    # CSV header: time since start (s) and value
    f.write("time_seconds,value\n")  

    while time.time() - inicio < TEMPO_LEITURA:
        if ser.in_waiting > 0:
            raw = ser.readline()
            valor = raw.decode(errors='ignore').strip()
            if not valor:
                continue
            elapsed = time.time() - inicio
            f.write(f"{elapsed:.3f},{valor}\n")

ser.close()
print(f"Finished. Data saved in '{FICHEIRO}'.")
