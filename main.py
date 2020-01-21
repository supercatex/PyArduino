import time
import serial


pin_states = "0" * 14
while True:
    with serial.Serial("COM5", 9600, bytesize=8, parity='N', dsrdtr=True, timeout=10) as ser:
        print(pin_states)
        ser.write(bytearray(f"{pin_states}\n", "UTF-8"))
        if pin_states[2] == "0":
            pin_states = pin_states[:2] + "1" + pin_states[3:]
            pin_states = pin_states[:3] + "0" + pin_states[4:]
        else:
            pin_states = pin_states[:2] + "0" + pin_states[3:]
            pin_states = pin_states[:3] + "1" + pin_states[4:]

        time.sleep(1)
