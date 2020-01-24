# pxt-swge-beacon

![alt text](https://raw.githubusercontent.com/ruthsarian/pxt-swge-beacon/master/icon.png "pxt-swge-beacon logo")

This PXT package allows the micro:bit to act as a SWGE beacon. The generic beacon allows users to specify their
own manufacturer's ID and beacon data. The other beacons are there to make it easier to create certain types
of beacons commonly found.

Example: https://makecode.microbit.org/_Km4T7WFyMaRe

## Blocks

### SWGE Location Beacon `zone`
* `zone`: Select from a drop-down list the location the beacon should represent.
* **note**: there is a version of this block that accepts an arbitrary 
value for `zone` under "bluetooth : more"

### SWGE Droid Beacon `personality`
* `personality`: Select from a drop-down list the personality the beacon should represent.
* **note**: there is a version of this block that accepts an arbitrary 
value for `personality` under "bluetooth : more"

### SWGE Generic Beacon  `manufacturerId, beaconData`
* `manufacturerId`: a value that identifies the manufacturer for the beacon. set this to `0x0183`
* `beaconData`: the data for the beacon. will be treated as hexadecimal if it begins with `0x` otherwise is treated as an array of bytes.
* **note**: this block may be found under "bluetooth : more"

## Supported targets
* for PXT/microbit
(The metadata above is needed for package search.)

