const int sensor_ph = A0;
void sensor_kelembaban ()
{
        float moisture_percentage;

        moisture_percentage = ( 100.00 - ( (analogRead(sensor_ph)/1023.00) * 100.00 ) ); 

        Serial.print("LEVEL SENSOR(in Percentage) = ");
        Serial.print(moisture_percentage);
        Serial.println("%");
        Cayenne.virtualWrite(4,moisture_percentage);

        if(moisture_percentage >= 80)
        {
          Serial.println("SANGAT LEMBAB");
        }
        else if (moisture_percentage >= 50 && moisture_percentage <= 80)
        {
          Serial.println("LEMBAB");
        }
        else if (moisture_percentage <= 50)
        {
        Serial.println("KERING");
        }
        delay(300);     
}
