#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>

#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>
#include <sensor_msgs/Temperature.h>
#include <sensor_msgs/FluidPressure.h>
#include <geometry_msgs/Vector3.h>


#include "Baro.hpp"
#include "HT.hpp"
#include "Imu.hpp"
#include "Mag.hpp"
#include "GPS.hpp"

#define I2C2_SCL PB10
#define I2C2_SDA PB11

#define SerialSpeed 115200

TwoWire dev_i2c(I2C2_SDA, I2C2_SCL);

// ROS
ros::NodeHandle  nh;
// Baro
std_msgs::Float32 baro_press_msg;
std_msgs::Float32 baro_temp_msg;
ros::Publisher Baro_Press("baro/pressure", &baro_press_msg);
ros::Publisher Baro_Temp("baro/temperature", &baro_temp_msg);
// HT 

// Imu 

// Mag 

// GPS

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    // Serial.begin(SerialSpeed);
    // Serial.println("begin");
    // Initialize I2C bus.
    nh.initNode();
    // Baro
    nh.advertise(Baro_Press);
    nh.advertise(Baro_Temp);
    // HT 

    // Imu 

    // Mag 

    // GPS

    dev_i2c.begin();
    // Serial.println("I2C done");
    while(Baro_Setup()!=0)
        ;

    while(HT_Setup()!=0)
        ;

    while(Imu_Setup()!=0)
        ;

    while(Mag_Setup()!=0)
        ;
    // GPS_Setup();
}

void loop()
{
    int32_t result = 0;
    float pressure = 123.0, temperatureP = 456.0;
    float humidity, temperatureH;
    int32_t acc[3], gyr[3], mag[3];
    char nmeaStr[100];
    
    // Baro
    if(Baro_Read(baro_press_msg.data,baro_temp_msg.data)!=0)
        Serial.println("pressure sensor went wrong !");
    Baro_Press.publish(&baro_press_msg);Baro_Temp.publish(&baro_temp_msg);

    // HT
    if (HT_Read(humidity, temperatureH) != 0)
        Serial.println("humidity sensor sent wrong !");
        
    // IMU
    if(Imu_Read(acc,gyr)!=0)
        Serial.println("IMU sensor sent wrong !");
        
    // MAG
    if(Mag_Read(mag)!=0)
        Serial.println("Mag sensor sent wrong !");
    // auto temp_msg = boost::make_shared<sensor_msgs::Temperature>();
    nh.spinOnce();
}
