#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>

#include <sensor_msgs/FluidPressure.h>
#include <sensor_msgs/Temperature.h>
#include <sensor_msgs/RelativeHumidity.h>

#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>

#include "Baro.hpp"
#include "HT.hpp"
#include "Imu.hpp"
#include "Mag.hpp"
// #include "GPS.hpp"

#define I2C2_SCL PB10
#define I2C2_SDA PB11

#define SerialSpeed 57600

TwoWire dev_i2c(I2C2_SDA, I2C2_SCL);

// ROS
ros::NodeHandle nh;
// Baro
std_msgs::Float32 baro_press_msg;
std_msgs::Float32 baro_temp_msg;
ros::Publisher Baro_Press("baro/pressure", &baro_press_msg);
ros::Publisher Baro_Temp("baro/temperature", &baro_temp_msg);
// HT
std_msgs::Float32 ht_humidity_msg;
std_msgs::Float32 ht_temp_msg;
ros::Publisher HT_Humidity("ht/humidity", &ht_humidity_msg);
ros::Publisher HT_Temp("ht/temperature", &ht_temp_msg);
// Imu
sensor_msgs::Imu imu_imu_msg;
ros::Publisher IMU_6DOF("imu/imu", &imu_imu_msg);

// Mag
sensor_msgs::MagneticField imu_mag_msg;
ros::Publisher IMU_Mag("imu/mag", &imu_mag_msg);

// GPS

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(SerialSpeed);
    Serial.println("begin");
    // Initialize I2C bus.
    dev_i2c.begin();

    nh.initNode();
    // Baro
    nh.advertise(Baro_Press);
    nh.advertise(Baro_Temp);

    // HT
    nh.advertise(HT_Humidity);
    nh.advertise(HT_Temp);

    // Imu
    nh.advertise(IMU_6DOF);

    // Mag
    nh.advertise(IMU_Mag);

    Serial.println("\nSetting up Baro ...");
    while (Baro_Setup() != 0)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nSetting up HT ...");
    while (HT_Setup() != 0)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nSetting up Imu ...");
    while (Imu_Setup() != 0)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nSetting up Mag ...");
    while (Mag_Setup() != 0)
    {
        delay(500);
        Serial.print(".");
    }
}

void loop()
{
    int32_t result = 0;
    float pressure = 123.0, temperatureP = 456.0;
    float humidity, temperatureH;
    int32_t acc[3], gyr[3], mag[3];
    char nmeaStr[100];

    // Baro
    if (Baro_Read(baro_press_msg.data, baro_temp_msg.data) != 0)
        Serial.println("pressure sensor went wrong !");
    else
        Baro_Press.publish(&baro_press_msg);
    Baro_Temp.publish(&baro_temp_msg);

    // HT
    if (HT_Read(humidity, temperatureH) != 0)
        Serial.println("humidity sensor sent wrong !");
    else
        HT_Humidity.publish(&ht_humidity_msg);
    HT_Temp.publish(&ht_temp_msg);

    // IMU
    if (Imu_Read(&imu_imu_msg) != 0)
        Serial.println("IMU sensor sent wrong !");
    else
        IMU_6DOF.publish(&imu_imu_msg);

    // imu_mag_msg.magnetic_field.x
    // MAG
    if (Mag_Read(&imu_mag_msg) != 0)
    {
        Serial.println("Mag sensor sent wrong !");
    }
    else
    {
        IMU_Mag.publish(&imu_mag_msg);
    }

    // auto temp_msg = boost::make_shared<sensor_msgs::Temperature>();
    nh.spinOnce();
}
