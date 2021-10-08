#include <HTS221Sensor.h>
#include <sensor_msgs/Temperature.h>
#include <sensor_msgs/RelativeHumidity.h>

#ifndef __HUMIDITY_
#define __HUMIDITY_

extern TwoWire dev_i2c;
extern HTS221Sensor  HumTemp;

int32_t HT_Setup();
int32_t HT_Read(sensor_msgs::RelativeHumidity *humidity, sensor_msgs::Temperature *temperature);

#endif