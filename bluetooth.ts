namespace bluetooth {
    /**
     * Activate SWGE Beacon
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
     * Activate SWGE Location Beacon
     * @param zone [1-7] set the location id for the beacon
     */
    //% block
    //% parts="bluetooth"
    //% shim=bluetooth::activateSwgeLocationBeacon
    //% zone.min=1 zone.max=7 zone.defl=1
    export function activateSwgeLocationBeacon(zone: number) {
        return;
    }
}
