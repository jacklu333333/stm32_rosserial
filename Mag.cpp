#include "Mag.hpp"

LIS3MDLSensor Magneto(&dev_i2c);

int32_t Mag_Setup()
{
  Magneto.begin();
  Magneto.Enable();
  
  return 0;
}

int32_t Mag_Read(int32_t *magnetometer)
{
  Magneto.GetAxes(magnetometer);

  // Output data.
  // Serial.print("Mag[mGauss]: ");
  // Serial.print(magnetometer[0]);
  // Serial.print(" ");
  // Serial.print(magnetometer[1]);
  // Serial.print(" ");
  // Serial.println(magnetometer[2]);

  return 0;
}
