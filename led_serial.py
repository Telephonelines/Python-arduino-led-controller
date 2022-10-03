import serial

s_port = 'COM5'

try:
	print("Connecting on port...", s_port)
	a = serial.Serial(s_port, 9600)
	print("Connected on port", s_port)
except Exception as e:
	print(e)
	exit()

print('This python program controls LEDs attached to an Arduino using serial communication. Type help for help.')

while True:
	try:
		color = input("User input: ")
		if color.casefold() == 'exit':
			print('Exiting Python...')
			exit()
		if color.casefold() == 'help':
			print('green to toggle green LED\nyellow to toggle yellow LED\nblue to toggle blue LED\nred to toggle red LED\nstatus to show status of all LEDs\non to toggle all LEDs ON\noff to toggle all LEDs OFF\ninvert to invert status of all LEDs\n')
			continue
		a.write(color.encode("utf-8"))
		data = a.readline()
		print(data.decode('utf-8'))
	except Exception as e:
		print(e)
		exit()