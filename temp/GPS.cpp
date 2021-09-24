#include <GPS.hpp>

void ppsHandler(void);

void ppsHandler(void)
{
   ppsTriggered = true;
}

void gpsHardwareReset()
{
   //reset the device
   digitalWrite(RESET_PIN, LOW);
   delay(50);
   digitalWrite(RESET_PIN, HIGH);

   //wait for reset to apply
   delay(2000);
}

//Read 32 bytes from I2C
void readI2C(char *inBuff)
{
   gps.beginTransmission(DEFAULT_DEVICE_ADDRESS);
   gps.write((uint8_t)DEFAULT_DEVICE_PORT);
   gps.endTransmission(false);
   gps.requestFrom((uint8_t)DEFAULT_DEVICE_ADDRESS, (uint8_t)32);
   int i = 0;
   while (gps.available())
   {
      inBuff[i] = gps.read();
      i++;
   }
}

//Send a NMEA command via I2C
void sendCommand(char *cmd)
{
   gps.beginTransmission(DEFAULT_DEVICE_ADDRESS);
   gps.write((uint8_t)DEFAULT_DEVICE_PORT);
   MicroNMEA::sendSentence(gps, cmd);
   gps.endTransmission(true);
}

int32_t GPS_Setup(void)
{
   gps.begin(); // gps

   //Start the module
   pinMode(RESET_PIN, OUTPUT);
   digitalWrite(RESET_PIN, HIGH);
   Serial.println("Resetting GPS module ...");
   gpsHardwareReset();
   Serial.println("... done");

   // Change the echoing messages to the ones recognized by the MicroNMEA library
   sendCommand((char *)"$PSTMSETPAR,1231,0x00000042");
   sendCommand((char *)"$PSTMSAVEPAR");

   //Reset the device so that the changes could take plaace
   sendCommand((char *)"$PSTMSRR");

   delay(4000);

   //Reinitialize I2C after the reset
   gps.begin();

   //clear i2c buffer
   char c;
   idx = 0;
   memset(buff, 0, 32);
   do
   {
      if (idx == 0)
      {
         readI2C(buff);
         delay(I2C_DELAY);
      }
      c = buff[idx];
      idx++;
      idx %= 32;
   } while ((uint8_t)c != 0xFF);

   pinMode(2, INPUT);
   attachInterrupt(digitalPinToInterrupt(2), ppsHandler, RISING);
}

int32_t GPS_Read(void)
{
   //While the message isn't complete
   while (!ppsTriggered)
   {
      char c;
      if (idx == 0)
      {
         readI2C(buff);
         delay(I2C_DELAY);
      }
      //Fetch the character one by one
      c = buff[idx];
      idx++;
      idx %= 32;
      //If we have a valid character pass it to the library
      if ((uint8_t)c != 0xFF)
      {
         Serial.print(c);
         nmea.process(c);
      }
   }
}