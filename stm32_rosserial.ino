#include "Baro.hpp"
#include "HT.hpp"
#include "Imu.hpp"
#include "Mag.hpp"
//#include "GPS.hpp"

#define I2C2_SCL PB10
#define I2C2_SDA PB11

#define SerialSpeed 115200

TwoWire dev_i2c(I2C2_SDA, I2C2_SCL);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(SerialSpeed);
    Serial.println("begin");
    // Initialize I2C bus.
    dev_i2c.begin();
    Serial.println("I2C done");
    Mag_Setup();
}

void loop()
{
    float pressure=123.0, temperatureP=456.0;
    float humidity, temperatureH;
    int32_t acc[3], gyr[3], mag[3];
    char nmeaStr[100];
    
    Mag_Read(mag);
    Serial.println("once");
    
}
