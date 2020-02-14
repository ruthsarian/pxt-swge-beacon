# pxt-swge-beacon

![alt text](https://raw.githubusercontent.com/ruthsarian/pxt-swge-beacon/master/icon.png "pxt-swge-beacon logo")

This PXT package allows the [micro:bit](https://en.wikipedia.org/wiki/Micro_Bit) to generate Bluetooth beacons to which droids from the droid depot will respond. 

## Usage

In [MakeCode](https://makecode.microbit.org/), open an existing project or create a new project. Click on the gear icon at the top-right and select *extensions* from the drop-down menu. In the search box enter `github:ruthsarian/pxt-swge-beacon`, press enter, and select `swge-beacon` when it comes up. Your project will now include SWGE beacon blocks under the `Bluetooth` section with some more advanced versions of those blocks under the `more` subsection.

Examples
* https://makecode.microbit.org/_Ly266TKHt71f
* https://makecode.microbit.org/_iMM1oxEAtWj7

## Block Descriptions

### SWGE Location Beacon `zone`
* `zone`: Select from a drop-down list the location the beacon should represent.
* **note**: there is a version of this block that accepts a numeric value for `zone` under "bluetooth : more"

### SWGE Droid Beacon `personality`
* `personality`: Select from a drop-down list the personality the beacon should represent.
* **note**: there is a version of this block that accepts a numeric value for `personality` under "bluetooth : more"

### SWGE Generic Beacon  `manufacturerId, beaconData`
* `manufacturerId`: a value that identifies the manufacturer for the beacon. set this to `0x0183`
* `beaconData`: the data for the beacon. will be treated as hexadecimal if it begins with `0x` otherwise is treated as an array of bytes.
* **note**: this block may be found under "bluetooth : more"

### SWGE Advanced Location Beacon `zone, react_interval, rssi`
* `zone`: Set the location zone for the beacon. Valid values are 1 - 7. 
* `react_interval`: Controls how long the droid will wait before its next reaction to the same beacon. This value is in seconds, then multiplied by 5. For example, a value of 24 would cause the droid to react every 2 minutes (24 x 5 = 120 seconds or 2 minutes). The minimum reaction time interval is 1 minute. This means any value less than 12 will be treated as 12 (12 x 5 = 60 seconds) by the droid.
* `rssi`: The minimum signal strength the droid must receive the beacon before it reacts. Value is in dBm and the default value is -90 which offers maximum distance (tens of feet). A value of around -26 will be a minimum distance of a few inches.
* **note**: this block can be found under the bluetooth "more" subsection.

## Supported targets
* for PXT/microbit
(The metadata above is needed for package search.)

