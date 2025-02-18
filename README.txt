Platform : Cayenne
Mikrokontrel : Nodemcu Esp8266
Sensor : - VL53L0X Sensor TOF
         - Soil Moisture Sensor
Aktuator : - Servo 180'
           - Relay 4 Channel
 
 
 PIN NodeMCU    >           PIN Sensor
    SDA              SDA (VL53L0X Sensor TOF)
    SCL              SCL (VL53L0X Sensor TOF)
    A0               Data Soil Moisture
 
 Pin NodeMCU     >       Servo Pin DATA
  D0 = 16              Pintu 0 (Utama)
  D3 = 0               Pintu 1
  D4 = 2               Pintu 2
  D5 = 14              Pintu 3
  
  Pin NodeMCU    >   Relay 4 Channel
  D6 = 12            IN3(Lampu Hijau)
  D7 = 13            IN2(Lampu Kuning)
  D8 = 15            IN1(Lampu Merah)
