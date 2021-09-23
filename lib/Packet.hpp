#include <cstring>

#define PACKET_SIZE 94

using namespace std;

typedef class _Packet
{
public:
    _Packet();
    ~_Packet();

    int get_data();
    void clear_data();
    int make_Packet();
    int add_CRCchucksum();
    void send_data();

protected:
    float pressure, temperatureP;
    float humidity, temperatureH;
    int acc[3], gyr[3], mag[3];
    char sentence[40];
    char packet[PACKET_SIZE];

private:
} Packet;
