namespace bluetooth {
    /**
     * Advertise SWGE Beacon
     * @param zone [1-7] set the location id for the beacon
     */
    //% block
    //% parts="bluetooth"
    //% shim=bluetooth::activateSwgeBeacon
    //% zone.min=1 zone.max=7 zone.defl=1
    export function activateSwgeBeacon(zone: number) {
        return;
    }

    /**
     * Advertise Generic Beacon
     * @param manufacturerId [0-65535]
     * @param beaconData Buffer, create with `pins.createBuffer(20)`
     */
    //% block="Generic Beacon|advertise Generic Beacon with Manufacturer ID %manufacturerId|, Beacon ID %beaconData"
    //% parts="bluetooth"
    //% shim=bluetooth::activateBeacon
    export function activateBeacon(manufacturerId: number, beaconData: Buffer) {
        return;
    }
}
