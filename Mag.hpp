#include <LIS3MDLSensor.h>
#include <sensor_msgs/MagneticField.h>

#ifndef __MAGNETOMETER_
#define __MAGNETOMETER_

extern TwoWire dev_i2c;
extern LIS3MDLSensor Magneto;

int32_t Mag_Setup();
int32_t Mag_Read(sensor_msgs::MagneticField *magnetometer);

#endif
