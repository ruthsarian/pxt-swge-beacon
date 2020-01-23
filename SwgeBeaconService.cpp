/** 
 * A class to advertise BLE Beacons
 */
#include <algorithm>

#include "MicroBit.h"
#include "pxt.h"
#include "ble/GapAdvertisingData.h"
#include "SwgeBeaconService.h"

namespace
{
const uint8_t SWGE_LOCATION_BEACON_PAYLOAD[] = {
	0x83, 0x01,		// manufacturer's id: 0x0183
	0x0A,			// type of beacon (location beacon)
	0x04, 			// length of beacon data
	0x01,			// location; also corresponds to the audio group the droid will select a sound from
	0x02,			// ? minimum interval between droid reactions to the beacon
	0xA6,			// expected RSSI, beacon is ignored if weaker
	0x01,			// ? 0 or 1 otherwise droid will ignore the beacon
};

const uint8_t SWGE_DROID_BEACON_PAYLOAD[] = {
	0x83, 0x01,		// manufacturer's id: 0x0183
    0x03,           // type of beacon (droid beacon)
    0x04,           // length of beacon data
    0x44,           // ??
    0x81,           // 0x01 + ( 0x80 if droid is paired with a remote)
    0x82,           // a combination of personality chip and affiliation IDs
    0x01,           // personality chip ID
};

const uint8_t SWGE_BEACON_NAME[] = {
	0x75, 0x42, 0x69, 0x74,		// 'uBit'
};
}

/**
 * Constructor
 * @param dev BLE device
 */
SwgeBeaconService::SwgeBeaconService(BLEDevice *dev) : ble(*dev)
{
}

void SwgeBeaconService::activateSwgeLocationBeacon(uint8_t zone)
{
    uint8_t msd[8];
    memcpy(msd, SWGE_LOCATION_BEACON_PAYLOAD, 8);

    // only zones used in the park, and which the droid will react to, are values 1 - 7.
    if (zone > 0 && zone < 8) {
        msd[4] = zone;
    }

    // add name 'uBit' to beacon
    uint8_t cln[4];
    memcpy(cln, SWGE_BEACON_NAME, 4);

    // start beacon
    advertiseBeacon(msd,8,cln,4);
}

void SwgeBeaconService::activateGenericBeacon(uint16_t manufacturerId, ManagedString beaconData)
{
    uint8_t data_len = beaconData.length();
    uint8_t payload[26];

    // limit beacon data to 24 bytes (+2 bytes for manufacturer's id)
    // see: https://stackoverflow.com/questions/33535404/whats-the-maximum-length-of-a-ble-manufacturer-specific-data-ad/33770673
    if (data_len > 24) {
        data_len = 24;
    }

    // insert manufacturer id into payload
    payload[0] = manufacturerId & 0xff;
    payload[1] = (manufacturerId >> 8) & 0xff;

    // insert beaconData into payload
    memcpy(&payload[2], beaconData.toCharArray(), data_len);

    // add name 'uBit' to beacon
    uint8_t cln[4];
    memcpy(cln, SWGE_BEACON_NAME, 4);

    // start beacon
    advertiseBeacon(payload, data_len+2, cln, 4);
}

void SwgeBeaconService::advertiseBeacon(const uint8_t *msd, uint8_t msd_len, const uint8_t *cln, uint8_t cln_len)
{
    ble.gap().stopAdvertising();
    ble.gap().clearAdvertisingPayload();
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);

    // only include the name if there's room for it
    if (msd_len + cln_len < 27 && cln_len > 0) {
        ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME , cln, cln_len);
    } 

    // limit manufacturer's data to just 26 bytes total
    else if (msd_len > 26) {
        msd_len = 26;
    }
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::MANUFACTURER_SPECIFIC_DATA, msd, msd_len);

    ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_NON_CONNECTABLE_UNDIRECTED);
    ble.gap().setAdvertisingInterval(1000);
    ble.gap().startAdvertising();
}
