#include <LSM6DSLSensor.h>
#include <sensor_msgs/Imu.h>

#ifndef __ACCELEROMETER_
#define __ACCELEROMETER_

extern TwoWire dev_i2c;
extern LSM6DSLSensor AccGyr;

int32_t Imu_Setup();
int32_t Imu_Read(sensor_msgs::Imu *imu);

#endif
