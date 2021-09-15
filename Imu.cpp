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

int32_t Imu_Read(int32_t *acc, int32_t *gyr)
{

  AccGyr.Get_X_Axes(acc);
  AccGyr.Get_G_Axes(gyr);

  // Output data.
  // Serial.print("Acc[mg]: ");
  // Serial.print(acc[0]);
  // Serial.print(" ");

  // Serial.print(" | Gyr[mdps]: ");
  // Serial.print(gyr[0]);
  return 0;
}
