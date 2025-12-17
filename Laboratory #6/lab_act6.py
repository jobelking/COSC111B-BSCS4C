import serial
import time
import os

try:
    arduino = serial.Serial(port='COM4', baudrate=9600, timeout=1)
    time.sleep(2)

    # NEW: Clear buffer so "Arduino Ready." does not get read as a response
    arduino.reset_input_buffer()

    while True:
        if arduino.in_waiting > 0:
            data = arduino.read(1).decode()
            if data == 'R':
                arduino.write(b"1")
            elif data == 'G':
                arduino.write(b"2")
            elif data == 'B':
                arduino.write(b"3")
            else:
                print(f"Command {data} is not a valid choice!!")
            time.sleep(1)

except serial.SerialException as e:
    print(f"Serial exception: {e}")
except Exception as ex:
    print(f"Unexpected error: {ex}")

    