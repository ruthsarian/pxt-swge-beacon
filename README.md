# pxt-swge-beacon

![alt text](https://raw.githubusercontent.com/ruthsarian/pxt-swge-beacon/master/icon.png "pxt-swge-beacon logo")

This PXT package allows the [micro:bit](https://en.wikipedia.org/wiki/Micro_Bit) to generate Bluetooth beacons to which droids from the droid depot will respond. 

## Usage

In [MakeCode](https://makecode.microbit.org/), open an existing project or create a new project. Click on the gear icon at the top-right and select *extensions* from the drop-down menu. In the search box enter `github:ruthsarian/pxt-swge-beacon`, press enter, and select `swge-beacon` when it comes up. Your project will now include SWGE beacon blocks under the `Bluetooth` section with some more advanced versions of those blocks under the `more` subsection.

MakeCode Examples
* https://makecode.microbit.org/_Ly266TKHt71f
* https://makecode.microbit.org/_iMM1oxEAtWj7

Video Tutorial
* https://www.youtube.com/watch?v=UUo-L128cFc

## Block Descriptions

### SWGE Location Beacon `zone`
* `zone`: Select from a drop-down list the location the beacon should represent.
* **numeric version**: there is a version of this block that accepts a numeric value for `zone` under "bluetooth : more"

### SWGE Droid Beacon `personality`
* `personality`: Select from a drop-down list the personality the beacon should represent.
* **usage note**: Droids will not react to this type of beacon for up to 2 hours after last encountering a location beacon.
* **numeric version**: there is a version of this block that accepts a numeric value for `personality` under "bluetooth : more"

### SWGE Advanced Location Beacon `zone, react_interval, rssi`
* `zone`: Set the location zone for the beacon. Valid values are 1 - 7. 
* `react_interval`: Controls how long the droid will wait before its next reaction to the same beacon. This value is in seconds, then multiplied by 5. For example, a value of 24 would cause the droid to react every 2 minutes (24 x 5 = 120 seconds or 2 minutes). The minimum reaction time interval is 1 minute. This means any value less than 12 will be treated as 12 (12 x 5 = 60 seconds) by the droid.
* `rssi`: The minimum signal strength the droid must receive the beacon before it reacts. Value is in dBm and the default value is -90 which offers maximum distance (tens of feet). A value of around -26 will be a minimum distance of a few inches.
* **note**: this block can be found under the bluetooth "more" subsection.

### SWGE Generic Beacon  `mfr_id, beacon_data`
* `mfr_id`: A 2-byte value (0-65535) that identifies the manufacturer for the beacon. For droid beacons this should be set to `0x0183`.
* `beacon_data`: The raw beacon data.
* **input values**: input values will be treated as hexadecimal if they begin with `0x` otherwise they are treated as an array of bytes.
* **note**: this block may be found under "bluetooth : more"

## Beacon Format
Droid beacons are typically 6 bytes long. Below is a table that describes the purpose of each byte for droid and location beacons.

### Location Beacon
This beacon identifies a location. These beacons are placed throughout the park and droids will react to them as they are encountered.

Example value: `0x0A040102A601`

|BYTE | Description | Example Value | Notes|
|---|---|---|---|
|01 | Beacon Type | 0x0A | Location Beacon|
|02 | Beacon Data Length | 0x04 | Value does not include the first two bytes; just the data that comes after|
|03 | Zone | 0x01 | Valid values are 1 - 7|
|04 | Reaction Interval | 0x02 | Multiply this value by 5 to get the number of seconds between droid reactions. Any value below 12 (60 seconds) will be treated as 12 (60 seconds) by the droid.|
|05 | Minimum RSSI in dBm | 0xA6 | A way to determine how close a droid must be to the beacon before it reacts. 0xA6 (-90 dBm) essentially tells the droid to respond at any signal strength. 0xE6 (-26 dBm) would tell the droid not to react until it is within about 1 foot of the droid.|
|06 | ? unknown ? | 0x01 | Droids will not react to the beacon is this byte is a value other than 0 or 1.|

### Droid Beacon
This beacon identifies a location. These beacons are placed throughout the park and droids will react to them as they are encountered.

Example value: `0x030444818201`

|BYTE | Description | Example Value | Notes|
|---|---|---|---|
|01 | Beacon Type | 0x03 | Droid Beacon|
|02 | Beacon Data Length | 0x04 | Value does not include the first two bytes; just the data that comes after|
|03 | ? unknown ? | 0x44 | |
|04 | Paired with Remote | 0x81 | 0x01 + (0x80 if the droid is paired with a remote).|
|05 | Affiliation | 0x82 | 0x80 + (Affiliation ID * 2)|
|06 | Personality | 0x01 | Personality Chip ID; 0x01 for unchipped R-unit, 0x02 for unchipped BB-unit.|

## Supported targets
* for PXT/microbit
(The metadata above is needed for package search.)