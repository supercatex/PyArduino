import serial


ser = serial.Serial(
        port="COM5",
        baudrate=9600,
        bytesize=8,
        parity='N',
        dsrdtr=True,
        timeout=10
    )
ser.write(bytearray("00000000000000\n", "UTF-8"))
ser.close()
