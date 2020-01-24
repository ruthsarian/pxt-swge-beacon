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
     * Advertise SWGE Location Beacon
     * @param zone [1-7] set the location id for the beacon
     */
    //% block
    //% parts="bluetooth"
    //% shim=bluetooth::activateSwgeLocationBeacon
    //% zone.min=1 zone.max=7 zone.defl=1
    export function activateSwgeLocationBeacon(zone: number) {
        return;
    }

    /**
     * Advertise Generic Beacon
     * @param manufacturerId [0-65535] the manufacturer's id
     * @param beaconData string ; the beacon data
     */
    //% block
    //% parts="bluetooth"
    //% shim=bluetooth::activateGenericBeacon
    export function activateGenericBeacon(manufacturerId: string, beaconData: string) {
        return;
    }
}
