#include "Baro.hpp"

LPS22HBSensor PressTemp(&dev_i2c);

int32_t Baro_Setup()
{
  // Initlialize components.
  PressTemp.begin();
  PressTemp.Enable();

  return 0;
}

int32_t Baro_Read(sensor_msgs::FluidPressure *pressure, sensor_msgs::Temperature *temperature)
{
  float tempP = 0.0;
  float tempT = 0.0;
  PressTemp.GetPressure(&tempP);
  PressTemp.GetTemperature(&tempT);

  pressure->fluid_pressure = tempP * 100;
  temperature->temperature = tempT;

  // Serial.print("Pres[hPa]: ");
  // Serial.print(pressure, 2);
  // Serial.print(" | Temp[C]: ");
  // Serial.println(temperature, 2);

  return 0;
}
