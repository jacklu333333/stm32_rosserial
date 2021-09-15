#include <HTS221Sensor.h>

#ifndef __HUMIDITY_
#define __HUMIDITY_

extern TwoWire dev_i2c;
extern HTS221Sensor  HumTemp;

int32_t HT_Setup();
int32_t HT_Read(float &humidity, float &temperature);

#endif