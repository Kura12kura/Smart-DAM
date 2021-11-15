void sensortof_setup ()
  {
    Wire.begin(); //SDA, SCL
    Wire.setClock(400000); // use 400 kHz I2C
    sensor_tof.setTimeout(500);
    if (!sensor_tof.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
    sensor_tof.setDistanceMode(VL53L1X::Long);
    sensor_tof.setMeasurementTimingBudget(50000);
    sensor_tof.startContinuous(50);
  }

void sensortof_loop ()
  {
  int distance = sensor_tof.read() / 10;
  Serial.print("KETINGIAN AIR :");
  Serial.print(distance);
  Serial.println("CM");
  delay(300);
  Cayenne.virtualWrite(5,distance);

  // SIAGA 3
  if (distance <=4)
  {

    pintu0.write(0);
    digitalWrite(hijau, LOW);
    digitalWrite(kuning, HIGH);
    digitalWrite(merah, HIGH);
    Serial.print("SIAGA 3 : ");
  }
  
  // SIAGA 2
  else if (distance >= 4 && distance <=10)
  {
    pintu0.write(90);
    digitalWrite(hijau, HIGH);
    digitalWrite(kuning, LOW);
    digitalWrite(merah, HIGH);
    Serial.print("SIAGA 2 : ");
    
//    mp3_play (3);
//    delay (5000);

  }
  else

  // SIAGA 1
  {
    pintu0.write(180);
    digitalWrite(hijau, HIGH);
    digitalWrite(kuning, HIGH);
    digitalWrite(merah, LOW);
    Serial.print("SIAGA 1 : ");
//    mp3_play (1);
//    delay (22000);
//    mp3_play (2);
//    delay (5000);
  }
  delay(300);
  }
