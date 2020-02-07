import serial
import time


ser = serial.Serial(
    port="COM5",
    baudrate=9600,
    bytesize=8,
    parity='N',
    dsrdtr=True,
    timeout=10
)
try:
    while True:
        ser.write(bytearray("00100000000000\n", "UTF-8"))
        time.sleep(1)
        ser.write(bytearray("00010000000000\n", "UTF-8"))
        time.sleep(1)
except Exception as e:
    print(e)
finally:
    ser.write(bytearray("00000000000000\n", "UTF-8"))
    ser.close()
