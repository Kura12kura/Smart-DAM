//////////////////////////////////////////CAYENNE////////////////
#define CAYENNE_PRINT Serial                                   //
//#define CAYENNE_DEBUG                                          //
#include <CayenneMQTTESP8266.h> //library dari platform Cayenne//
/////////////////////////////////////////////////////////////////

////////////////////////////////Sensor TOF//////////////////////
#include <Wire.h> // Library komunikasi I2C SDA:SCL           //
#include <VL53L1X.h> // library sensor TOF                    //
///////////////////////////////////////////////////////////////

///////////////////// SERVO //////////////////////////////////
#include <Servo.h> // Library Servo MG996R                  //
/////////////////////////////////////////////////////////////

/////////////////////// DFPlayer Mini //////////////////////////
#include <DFPlayer_Mini_Mp3.h> // Library DFPlayer Mini       //
#include <SoftwareSerial.h> // Library Komunikas Serial TX:RX //
///////////////////////////////////////////////////////////////

/////////////////// int tipe data yang menyimpan bilangan, cosntanta= nilai tidak berubah /////
const int hijau = 12; //IN3=D6=12                                                            //
const int kuning = 13; //IN2=D7=13                                                          //
const int merah = 15;  //IN1=D8=15                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////// inisialisai dari nama servo dan sensor TOF ///////
VL53L1X sensor_tof;                                                      //
Servo pintu0;                                                            //
Servo pintu1;                                                            //
Servo pintu2;                                                            //
Servo pintu3;                                                            //
//////////////////////////////////////////////////////////////////////////

char ssid[]= "pusat riset anak negri"; // isi dengan nama wifi yang kalian
char pass[]= "pejuang01"; // sesuaikan pass wifi nya
char username[] = "8ce08eb0-18ca-11ec-8da3-474359af83d7"; // dapatkan username,pass,clientID yang dapat di cayenne
char password[] = "8ae108b85fa0f0c422ca1756499319d3f492fd05";
char clientID[] = "9ec88280-19f7-11ec-8da3-474359af83d7";

void setup() {
  sensortof_setup ();
  Serial.begin(115200);
  Cayenne.begin(username,password,clientID,ssid,pass);

  pinMode(hijau, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(merah, OUTPUT);  

  pintu0.attach(16); //D0=16
  pintu1.attach(0); //D3=0
  pintu2.attach(2); //D4=2
  pintu3.attach(14); //D5=14

  mp3_set_serial (Serial);
  mp3_set_volume (20); //volume 0-30
}

void loop() {
  Cayenne.loop();
  sensor_kelembaban ();
  sensortof_loop ();
}

CAYENNE_IN(0)
{
 pintu0.write(getValue.asInt());
}
CAYENNE_IN(1)
{
 pintu1.write(getValue.asInt());
}
CAYENNE_IN(2)
{
 pintu2.write(getValue.asInt());
}
CAYENNE_IN(3)
{
 pintu3.write(getValue.asInt());
}
