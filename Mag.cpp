#include "Mag.hpp"

LIS3MDLSensor Magneto(&dev_i2c);

int32_t Mag_Setup()
{
  Magneto.begin();
  Magneto.Enable();
  
  return 0;
}

int32_t Mag_Read(sensor_msgs::MagneticField *magnetometer)
{
  int32_t mag[3];
  Magneto.GetAxes(mag);
  // magnetometer->serialize(&mag);

  magnetometer->magnetic_field.x=float(mag[0])/10000000*-1;
  magnetometer->magnetic_field.y=float(mag[1])/10000000*-1;
  magnetometer->magnetic_field.z=float(mag[2])/10000000;

  // Output data.
  // Serial.print("Mag[mGauss]: ");
  // Serial.print(magnetometer[0]);
  // Serial.print(" ");
  // Serial.print(magnetometer[1]);
  // Serial.print(" ");
  // Serial.println(magnetometer[2]);

  return 0;
}
