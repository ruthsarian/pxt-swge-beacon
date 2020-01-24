# pxt-swge-beacon

This PXT package allows the micro:bit to act as a SWGE beacon. The generic beacon allows users to specify their
own manufacturer's ID and beacon data. The other beacons are there to make it easier to create certain types
of beacons commonly found.

## Blocks

### SWGE Generic Beacon  `manufacturerId` `beaconData`
* `manufacturerId`: a value that identifies the manufacturer for the beacon. set this to `0x0183`
* `beaconData`: the data for the beacon. will be treated as hexadecimal if it begins with `0x` otherwise is treated as an array of bytes.

### SWGE Location Beacon `zone`
* `zone`: a value between 1 and 7. It identifies an area within the park and a corresponding audio group the droid should utilize when reacting to the beacon.

### SWGE Droid Beacon
* *not yet implemented*

## TODO
- [ ] Add "icon.png" image (300x200) in the root folder
- [ ] Get your package reviewed and approved https://makecode.microbit.org/extensions/approval

## Supported targets
* for PXT/microbit
(The metadata above is needed for package search.)

