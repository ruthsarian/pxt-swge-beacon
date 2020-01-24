# pxt-swge-beacon

![alt text](https://raw.githubusercontent.com/ruthsarian/pxt-swge-beacon/master/icon.png "pxt-swge-beacon logo")

This PXT package allows the [micro:bit](https://en.wikipedia.org/wiki/Micro_Bit) to generate Bluetooth beacons to which droids from the droid depot will respond. 

## Usage

In [MakeCode](https://makecode.microbit.org/), open an existing project or create a new project. Click on the gear icon at the top-right and select *extensions* from the drop-down menu. In the search box enter `github:ruthsarian/pxt-swge-beacon`, press enter, and select `swge-beacon` when it comes up. Your project will now include SWGE beacon blocks under the `Bluetooth` section with some more advanced versions of those blocks under the `more` subsection.

Example: https://makecode.microbit.org/_Km4T7WFyMaRe

## Block Descriptions

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

