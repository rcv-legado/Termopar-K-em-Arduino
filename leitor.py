import serial

from datetime import datetime

serial_port = 'COM5';
baud_rate = 9600; #no arduino Serial.begin(baud_rate)

ser = serial.Serial(serial_port, baud_rate)

print("======================================================================");
print("Aquisitor de Dados - Temperatura");
print("======================================================================");
print("Desenvolvido por Ricardo Cezar Volert");
print("Utilizando: Arduino com o Termopar K e o Amplificador de Sinal MAX6675");
print("======================================================================");
print("Data ; Hora ; Temperatura em Celsius");

while True:
    now = datetime.now()
    line = ser.readline();
    line = line.decode("utf-8")
    print(str(now.year) + "-" + str(now.month).zfill(2) + "-" + str(now.day).zfill(2) + " ; " + str(now.hour).zfill(2) + ":" + str(now.minute).zfill(2) + ":" + str(now.second).zfill(2) + " ; " + str(line));
    with open ('resultados.csv', 'a') as f:
        f.write (str(now.year) + "-" + str(now.month).zfill(2) + "-" + str(now.day).zfill(2) + " ; " + str(now.hour).zfill(2) + ":" + str(now.minute).zfill(2) + ":" + str(now.second).zfill(2) + " ; " + str(line));
