#ifndef __BLEBEACON_H__
#define __BLEBEACON_H__

#include "ble/BLE.h"

/** 
 * A class to advertise BLE Beacons
 */
class SwgeBeaconService
{
  public:
    /**
     * Constructor
     * @param dev BLE device
     */
    SwgeBeaconService(BLEDevice *device);

    /**
     * Advertise as AltBeacon
     * 
     * @param manufacturerId mfg ID
     * @param beaconId 20 bytes
     * @param refRSSI reference RSSI from 0 to -127
     */
    void activateSwgeBeacon(uint8_t zone);

  private:
    BLEDevice &ble;
};

#endif /* __BLEBEACON_H__ */
