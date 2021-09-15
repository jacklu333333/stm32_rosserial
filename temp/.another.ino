

#define I2C2_SCL    PB10
#define I2C2_SDA    PB11

#define SerialSpeed 9600

TwoWire dev_i2c(I2C2_SDA, I2C2_SCL);


void setup(){
    Serial.begin(SerialSpeed);

    // Initialize I2C bus.
    dev_i2c.begin();
}