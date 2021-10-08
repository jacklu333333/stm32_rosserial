#include <LPS22HBSensor.h>
#include <sensor_msgs/FluidPressure.h>
#include <sensor_msgs/Temperature.h>

#ifndef __BAROMETER_
#define __BAROMETER_

extern TwoWire dev_i2c;
extern LPS22HBSensor PressTemp;

int32_t Baro_Setup();
int32_t Baro_Read(sensor_msgs::FluidPressure *pressure, sensor_msgs::Temperature *temperature);

#endif
