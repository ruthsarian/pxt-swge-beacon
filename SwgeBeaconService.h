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
     * Advertise as SWGE Beacon
     * 
     * @param zone Group ID
     */
    void activateSwgeBeacon(uint8_t zone);

  private:
    BLEDevice &ble;

    void advertiseBeacon(const uint8_t *msd, uint8_t msd_len, const uint8_t *cln, uint8_t cln_len);
};

#endif /* __BLEBEACON_H__ */
