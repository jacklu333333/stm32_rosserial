#include "HT.hpp"

HTS221Sensor HumTemp(&dev_i2c);
int32_t HT_Setup()
{
  HumTemp.begin();
  HumTemp.Enable();

  return 0;
}

int32_t HT_Read(sensor_msgs::RelativeHumidity *humidity, sensor_msgs::Temperature *temperature)
{
  float tempH = 0.0;
  float tempT = 0.0;
  // Read humidity and temperature.
  HumTemp.GetHumidity(&tempH);
  HumTemp.GetTemperature(&tempT);

  humidity->relative_humidity = tempH / 100;
  temperature->temperature = tempT;

  // Output data.
  // Serial.print("Hum[%]: ");
  // Serial.print(humidity, 2);
  // Serial.print(" | Temp[C]: ");
  // Serial.println(temperature, 2);

  return 0;
}
