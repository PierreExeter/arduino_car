from bluetooth import *
from getch import getch

# the car controler MAC address
device='98:D3:31:70:15:FA'
# comunication port
port=1

# open RFCOMM socket
sock=BluetoothSocket( RFCOMM )
# connect to the car bluetooth device
try:
    sock.connect ( (device, port) )
    print("Connected to the car.")
except:
    print("The bluetooth device %s not found." % device)
    print("Check the connection of the device and try again.")
    exit(1)

print("""----------------------------------------
\tPlease send your instruction:
\t7 (FL)\t8 (F)\t9 (FR)
\t4 (L)\t5 (S)\t6 (R)
\t1 (BL)\t2 (B)\t3 (BL)

\tF -- forward
\tB -- backward
\tR -- right
\tL -- left
\tS -- stop

Press "V" to honk the horn.
----------------------------------------
(press "q" to quit)
""")

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
    elif (inst == "V"):
        sock.send ("V") # horn
    
# close the connection
sock.close()
