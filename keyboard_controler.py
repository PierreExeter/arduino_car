from bluetooth import *
from time import sleep
from getch import getch

# the car controler MAC address
device='98:D3:31:70:15:FA'
# comunication port
port=1

# open RFCOMM socket
sock=BluetoothSocket( RFCOMM )
# connect to the car bluetooth device
sock.connect ( (device, port) )

# initial instruction
inst="5"
while not inst == "q":
    inst=getch()
    # sent instruction to the car
    if (inst == "8"):
        sock.send ("F") # forward
    elif (inst == "2"):
        sock.send ("B") # backward
    elif (inst == "4"):
        sock.send ("L") # left
    elif (inst == "6"):
        sock.send ("R") # right
    elif (inst == "5"):
        sock.send ("S") # stop
    elif (inst == "7"):
        sock.send ("G") # forward left
    elif (inst == "9"):
        sock.send ("I") # forward right
    elif (inst == "1"):
        sock.send ("H") # backward left
    elif (inst == "3"):
        sock.send ("J") # backward right
    
# close the connection
sock.close()
