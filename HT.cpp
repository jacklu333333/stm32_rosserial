#include "HT.hpp"

HTS221Sensor HumTemp(&dev_i2c);
int32_t HT_Setup()
{
  HumTemp.begin();
  HumTemp.Enable();

  return 0;
}

int32_t HT_Read(float &humidity, float &temperature)
{
  // Read humidity and temperature.
  HumTemp.GetHumidity(&humidity);
  HumTemp.GetTemperature(&temperature);

  // Output data.
  // Serial.print("Hum[%]: ");
  // Serial.print(humidity, 2);
  // Serial.print(" | Temp[C]: ");
  // Serial.println(temperature, 2);

  return 0;
}
