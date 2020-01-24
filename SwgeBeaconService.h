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
     * Advertise as SWGE Location Beacon
     * 
     * @param zone Group ID
     */
    void activateSwgeLocationBeacon(uint8_t zone);

    /**
     * Advertise as Generic Manufacturer's Data Beacon
     * 
     * @param manufacturerId 2-byte manufacturer's id value
     * @param beaconData the data for the beacon
     */
    void activateGenericBeacon(uint16_t manufacturerId, ManagedString beaconData);

  private:
    BLEDevice &ble;
    uint8_t char2int(char c);
    void advertiseBeacon(const uint8_t *msd, uint8_t msd_len, const uint8_t *cln, uint8_t cln_len);
};

#endif /* __BLEBEACON_H__ */
