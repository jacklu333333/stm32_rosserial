#include "Imu.hpp"

extern LSM6DSLSensor AccGyr(&dev_i2c, LSM6DSL_ACC_GYRO_I2C_ADDRESS_LOW);

int32_t Imu_Setup()
{
  // Initlialize components.
  AccGyr.begin();
  AccGyr.Enable_X();
  AccGyr.Enable_G();
  return 0;
}

int32_t Imu_Read(sensor_msgs::Imu *imu)
{
  int32_t acc[3];
  int32_t gyr[3];

  AccGyr.Get_X_Axes(acc);
  AccGyr.Get_G_Axes(gyr);

  imu->angular_velocity.x = gyr[0] * 3.14 / 180000;
  imu->angular_velocity.y = gyr[1] * 3.14 / 180000;
  imu->angular_velocity.z = gyr[2] * 3.14 / 180000;

  imu->linear_acceleration.x = acc[0] * 9.80665 / 1000;
  imu->linear_acceleration.y = acc[1] * 9.80665 / 1000;
  imu->linear_acceleration.z = acc[2] * 9.80665 / 1000;

  // Output data.
  // Serial.print("Acc[mg]: ");
  // Serial.print(acc[0]);
  // Serial.print(" ");

  // Serial.print(" | Gyr[mdps]: ");
  // Serial.print(gyr[0]);
  // Serial.print("\n");

  return 0;
}
