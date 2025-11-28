# -------------------------------------------------------
# CONFIGURATIONS
# -------------------------------------------------------
import serial
import time

PORTA = "COM3"                 # <- Change to the correct port
BAUD = 9600
FICHEIRO = "dada_serial.csv"
TEMPO_LEITURA = 5              # Seconds
# -------------------------------------------------------

try:
    ser = serial.Serial(PORTA, BAUD, timeout=1)
    time.sleep(2)  # Wait for the Arduino to restart
    print(f"Connected to {PORTA} at {BAUD} baud.")
except Exception as e:
    print(f"Error connecting to serial port: {e}")
    quit()

inicio = time.time()

with open(FICHEIRO, "w") as f:
    # Optional header
    f.write("value\n")  

    while time.time() - inicio < TEMPO_LEITURA:
        if ser.in_waiting > 0:
            print("Reading data...")
            print(inicio)
            valor = ser.readline().decode(errors='ignore').strip()
            f.write(valor + "\n")

ser.close()
print(f"Finished. Data saved in '{FICHEIRO}'.")
