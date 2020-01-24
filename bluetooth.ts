namespace bluetooth {
    /**
     * SWGE Beacon
     * @param zone [1-7] set the location id for the beacon
     */
    //% blockId=swge_beacon block="Location Beacon for| Zone: %zone"
    //% parts="bluetooth"
    //% shim=bluetooth::activateSwgeBeacon
    //% zone.min=1 zone.max=7 zone.defl=1
    //% deprecated=true
    export function activateSwgeBeacon(zone: number): void {
        return;
    }
    /**
     * SWGE Location Beacon
     * @param zone [1-7] set the location id for the beacon
     */
    //% blockId=swge_location_beacon block="Location Beacon for| Zone: %zone"
    //% parts="bluetooth"
    //% shim=bluetooth::activateSwgeLocationBeacon
    //% zone.min=1 zone.max=7 zone.defl=1
    //% inlineInputMode=external
    export function activateSwgeLocationBeacon(zone: number): void {
        return;
    }
    /**
     * SWGE Generic Beacon
     * @param manufacturerId [0-65535] the manufacturer's id
     * @param beaconData string ; the beacon data
     */
    //% blockId=swge_generic_beacon block="Generic Beacon with| Manufacturer's ID: %manufacturerId|, Beacon Data: %beaconData"
    //% parts="bluetooth"
    //% shim=bluetooth::activateGenericBeacon
    //% manufacturerId.shadowOptions.toString=true
    //% beaconData.shadowOptions.toString=true
    //% inlineInputMode=external
    export function activateGenericBeacon(manufacturerId: string, beaconData: string): void {
        return;
    }
}
