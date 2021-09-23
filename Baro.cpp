#include "Baro.hpp"

LPS22HBSensor PressTemp(&dev_i2c);

int32_t Baro_Setup()
{
  // Initlialize components.
  PressTemp.begin();
  PressTemp.Enable();
  
  return 0;
}

int32_t Baro_Read(float &pressure, float &temperature)
{
  PressTemp.GetPressure(&pressure);
  PressTemp.GetTemperature(&temperature);

  // Serial.print("Pres[hPa]: ");
  // Serial.print(pressure, 2);
  // Serial.print(" | Temp[C]: ");
  // Serial.println(temperature, 2);

  return 0;
}
