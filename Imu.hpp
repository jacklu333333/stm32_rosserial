#include <LSM6DSLSensor.h>

#ifndef __ACCELEROMETER_
#define __ACCELEROMETER_

extern TwoWire dev_i2c;
extern LSM6DSLSensor AccGyr;

int32_t Imu_Setup();
int32_t Imu_Read(int32_t *acc, int32_t *gyr);

#endif
