#include <MicroNMEA.h>
#include <Wire.h>

//I2C communication parameters
#define DEFAULT_DEVICE_ADDRESS 0x3A
#define DEFAULT_DEVICE_PORT 0xFF
#define I2C_DELAY 1

#define RESET_PIN 7

#if defined(ARDUINO_SAM_DUE)
#define DEV_I2C Wire1
#elif defined(ARDUINO_ARCH_STM32L0)
#define DEV_I2C Wire
#elif defined(ARDUINO_ARCH_STM32)
#define DEV_I2C Wire
#elif defined(ARDUINO_ARCH_AVR)
#define DEV_I2C Wire
#endif

// Refer to Stream devices by use
TwoWire &gps = DEV_I2C;

//I2C read data structures
char buff[32];
int idx = 0;

//MicroNMEA library structures
char nmeaBuffer[100];
MicroNMEA nmea(nmeaBuffer, sizeof(nmeaBuffer));

bool ledState = LOW;
volatile bool ppsTriggered = false;

void ppsHandler(void);

void ppsHandler(void);

void gpsHardwareReset();

//Read 32 bytes from I2C
void readI2C(char *inBuff);

//Send a NMEA command via I2C
void sendCommand(char *cmd);

int32_t GPS_Setup(void);

int32_t GPS_Read(void);