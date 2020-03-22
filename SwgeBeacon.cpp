#include "pxt.h"
#include "SwgeBeaconService.h"
using namespace pxt;
/**
 * A set of functions to advertise beacon with Bluetooth
 */
namespace bluetooth
{
SwgeBeaconService *pBeaconInstance = nullptr;
SwgeBeaconService *getBeaconService()
{
    if (pBeaconInstance == nullptr)
    {
        pBeaconInstance = new SwgeBeaconService(uBit.ble);
    }
    return pBeaconInstance;
}

//%
void activateSwgeLocationBeaconAdvanced(uint8_t zone, uint8_t react_interval, int8_t rssi)
{
    // only zones used in the park, and which the droid will react to, are values 1 - 7.
    if (zone < 0 || zone > 7) {
        zone = 1;
    }

    getBeaconService()->activateSwgeLocationBeacon(zone, react_interval, (uint8_t)(rssi & 0xFF));
}

//%
void activateSwgeLocationBeacon(uint8_t zone)
{
    // most common values found throughout the park
    uint8_t react_interval = 0x02;
    char rssi = 0xA6;

    activateSwgeLocationBeaconAdvanced(zone, react_interval, rssi);
}

//%
void activateSwgeDroidBeacon(uint8_t personality)
{
    // limit value of personality to between 0 and 8
    personality %= 9;

    // droid is paired with a remote
    uint8_t is_paired = 1;

    // establish chip's affiliation, 0 = scoundrel
    uint8_t affiliation = 0;

    // resistance = 1
    if (personality == 3 || personality == 6) {
        affiliation = 1;

    // first order = 2
    } else if (personality == 5 || personality == 8) {
        affiliation = 2;
    }

    getBeaconService()->activateSwgeDroidBeacon(personality, affiliation, is_paired);
}

//%
void activateGenericBeacon(String mfr_id, String beacon_data)
{
    getBeaconService()->activateGenericBeacon(MSTR(mfr_id), MSTR(beacon_data));
}

//%
void activateSwgeBeacon(uint8_t zone)
{
    activateSwgeLocationBeacon(zone);
}
}
