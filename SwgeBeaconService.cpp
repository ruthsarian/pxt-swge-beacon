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
	0x02,			// minimum interval between droid reactions to the beacon; this value is multiplied by 5 to determine the interval in seconds. droids have a minimum reaction time of 60 seconds
	0xA6,			// expected RSSI, beacon is ignored if weaker than value specified
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

void SwgeBeaconService::activateSwgeLocationBeacon(uint8_t zone, uint8_t react_interval, uint8_t rssi)
{
    uint8_t msd[8];
    memcpy(msd, SWGE_LOCATION_BEACON_PAYLOAD, 8);

    // update payload with parameters
    msd[4] = zone & 0xff;
    msd[5] = react_interval & 0xff;
    msd[6] = rssi & 0xff;

    // add name 'uBit' to beacon
    uint8_t cln[4];
    memcpy(cln, SWGE_BEACON_NAME, 4);

    // start beacon
    advertiseBeacon(msd,8,cln,4);
}

void SwgeBeaconService::activateSwgeDroidBeacon(uint8_t personality, uint8_t affiliation, uint8_t is_paired)
{
    // load default droid beacon payload
    uint8_t msd[8];
    memcpy(msd, SWGE_DROID_BEACON_PAYLOAD, 8);

    // modify payload appropriately based on established information
    msd[5] = 0x01 | ((is_paired   << 7) & 0xff);
    msd[6] = 0x82 | ((affiliation << 3) & 0xff);
    msd[7] = personality & 0xff;

    // add name 'uBit' to beacon
    uint8_t cln[4];
    memcpy(cln, SWGE_BEACON_NAME, 4);

    // start beacon
    advertiseBeacon(msd,8,cln,4);
}

void SwgeBeaconService::activateGenericBeacon(ManagedString mfr_id, ManagedString beacon_data)
{
    // initialize payload
    uint8_t msd[26];
    memset(msd, 0, 26);

    // sort out manufacturer's ID
    uint16_t mfId = (uint16_t)strtol(mfr_id.toCharArray(), NULL, 0);

    // insert manufacturer id into payload
    msd[0] = mfId & 0xff;
    msd[1] = (mfId >> 8) & 0xff;

    // start sorting out data
    uint8_t data_len = beacon_data.length();

    // is data in hexadecimal format? 
    if ( beacon_data.substring(0,2) == "0x") {
        uint8_t i = 2;
        uint8_t d = 0;
        uint8_t new_data_len = 0;

        // handle odd number of characters by assuming missing leading zero
        if ( data_len % 2 != 0 ){
            msd[new_data_len+2] = char2int(beacon_data.charAt(i)) & 0x0f;
            new_data_len++;
            i++;
        }

        // loop through data, converting hex to byte
        for (;i<data_len;i+=2) {
            d  = (char2int(beacon_data.charAt(i  )) << 4 & 0xf0);
            d += (char2int(beacon_data.charAt(i+1))      & 0x0f);
            msd[new_data_len+2] = d;
            new_data_len++;
        }

        data_len = new_data_len;

    // if not in hex, treat string as byte array
    } else {
        if (data_len > 24) {
            data_len = 24;
        }

        // load data into payload
        memcpy(&msd[2], beacon_data.toCharArray(), data_len);
    }

    // add 'uBit' name to beacon
    uint8_t cln[4];
    memcpy(cln, SWGE_BEACON_NAME, 4);

    // advertise the beacon
    advertiseBeacon(msd,data_len+2,cln,4);
}

uint8_t SwgeBeaconService::char2int(char c) {
    if ((c >= '0') && (c <= '9')) {
        return c - '0';
    } else if ((c >= 'a') && (c <= 'f')) {
        return c - 'a' + 10;
    } else if ((c >= 'A') && (c <= 'F')) {
        return c - 'A' + 10;
    } else {
        return 0;
    }
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
