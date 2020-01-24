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
     * SWGE Location Beacon
     * 
     * @param zone [1-7] the location id
     * @param react_interval [0-255] minimum interval between droid reaction to same beacon
     * @param rssi [0-255] is actually a SIGNED value that identifies the minimum rssi before a droid will react
     */
    void activateSwgeLocationBeacon(uint8_t zone, uint8_t react_interval, uint8_t rssi);

    /**
     * SWGE Droid Beacon
     * 
     * @param personality [0-8] Identify the personality of the droid
     * @param affiliation [0-2] Identify the affiliation of the droid
     * @param is_paired [0-1] Identify whether or not the droid is paired with a controller
     */
    void activateSwgeDroidBeacon(uint8_t personality, uint8_t affiliation, uint8_t is_paired);

    /**
     * Generic Manufacturer's Data Beacon
     * 
     * @param mfr_id 2-byte manufacturer's id value
     * @param beacon_data the data for the beacon
     */
    void activateGenericBeacon(ManagedString mfr_id, ManagedString beacon_data);

  private:
    BLEDevice &ble;
    uint8_t char2int(char c);
    void advertiseBeacon(const uint8_t *msd, uint8_t msd_len, const uint8_t *cln, uint8_t cln_len);
};

#endif /* __BLEBEACON_H__ */
