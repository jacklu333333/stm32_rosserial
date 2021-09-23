#include "Packet.hpp"
#include <iostream>

Packet::_Packet()
{

    memset(&pressure, 0, sizeof(float));
    memset(&temperatureP, 0, sizeof(float));

    memset(&humidity, 0, sizeof(float));
    memset(&temperatureH, 0, sizeof(float));

    memset(acc, 0, sizeof(int) * 3);
    memset(gyr, 0, sizeof(int) * 3);
    memset(mag, 0, sizeof(int) * 3);

    memset(sentence, 0, sizeof(char) * 40);
    memset(packet, 0, sizeof(char) * 94);
}

Packet::~_Packet()
{
    cout << "--------------------------------" << endl;
}

int Packet::get_data()
{
    // read Baro
    // read HT
    // read Imu
    // read Mag
    // Read GPS
    return 0;
}

void Packet::clear_data()
{
    memset(&pressure, 0, sizeof(float));
    memset(&temperatureP, 0, sizeof(float));

    memset(&humidity, 0, sizeof(float));
    memset(&temperatureH, 0, sizeof(float));

    memset(acc, 0, sizeof(int) * 3);
    memset(gyr, 0, sizeof(int) * 3);
    memset(mag, 0, sizeof(int) * 3);

    memset(sentence, 0, sizeof(char) * 40);
    memset(packet, 0, sizeof(char) * 94);
}

int Packet::make_Packet()
{
    memset(packet, 0, sizeof(packet));

    // read Baro
    memcpy(&packet[0], &pressure, sizeof(float));
    memcpy(&packet[4], &temperatureP, sizeof(float));
    // read HT
    memcpy(&packet[8], &humidity, sizeof(float));
    memcpy(&packet[12], &temperatureH, sizeof(float));
    // read Imu
    memcpy(&packet[16], acc, sizeof(int) * 3);
    memcpy(&packet[28], gyr, sizeof(int) * 3);
    // read Mag
    memcpy(&packet[40], mag, sizeof(int) * 3);
    // Read GPS
    memcpy(&packet[52], sentence, sizeof(char) * 40);
    return 0;
}
int Packet::add_CRCchucksum()
{
    unsigned int CRC = 0xFFFFFFFFFFFF;

    for (int i = 0; i < PACKET_SIZE; i++)
    {
        CRC;
    }

    return 0;
}
void Packet::send_data()
{
}

int main(int argc, char *argv[])
{
    cout << "hi" << endl;

    Packet mypacket;
    mypacket.~Packet();
    cout << sizeof(mypacket) << endl;
    cout << sizeof(float) << endl;
    return 0;
}