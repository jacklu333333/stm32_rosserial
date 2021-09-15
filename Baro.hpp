#include <LPS22HBSensor.h>

#ifndef __BAROMETER_
#define __BAROMETER_

extern TwoWire dev_i2c;
extern LPS22HBSensor PressTemp;

int32_t Baro_Setup();
int32_t Baro_Read(float &pressure, float &temperature);

#endif
