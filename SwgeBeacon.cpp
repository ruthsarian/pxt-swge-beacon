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
void activateSwgeBeacon(uint8_t zone)
{
    getBeaconService()->activateSwgeLocationBeacon(zone);
}

//%
void activateSwgeLocationBeacon(uint8_t zone)
{
    getBeaconService()->activateSwgeLocationBeacon(zone);
}
}
