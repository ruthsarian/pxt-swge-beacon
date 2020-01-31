enum Personality {
    //None = 0,
    //% block="R-unit"
    R = 1,
    //% block="BB-unit"
    BB = 2,
    Blue = 3,
    Gray = 4,
    Red = 5,
    Orange = 6,
    Purple = 7,
    Black = 8
}
enum Zone {
    //None = 0,
    Marketplace = 1,
    //% block="Behind Droid Depot"
    BehindDroidDepot = 2,
    //% block="Resistance Base"
    ResistanceBase = 3,
    //% block="Hidden Area"
    Unknown = 4,
    //% block="Droid Depot"
    DroidDepot = 5,
    //% block="Dok Ondar's"
    DokOndars = 6,
    //% block="First Order Base"
    FirstOrderBase = 7
}
namespace bluetooth {
    /**
     * SWGE Location Beacon with Drop-Down Selction
     * @param zone [1-7] set the location id for the beacon
     */
    //% blockId=swge_location_beacon_dropdown block="SWGE Location Beacon| for zone: %zone"
    //% parts="bluetooth"
    //% shim=bluetooth::activateSwgeLocationBeacon
    //% inlineInputMode=external
    export function activateSwgeLocationBeaconDropDown(zone: Zone): void {
        return;
    }
    /**
     * SWGE Droid Beacon with Drop-Down Selction
     * @param personality [0-7] set the personality of the droid
     */
    //% blockId=swge_droid_beacon_dropdown block="SWGE Droid Beacon| with personality: %personality"
    //% parts="bluetooth"
    //% shim=bluetooth::activateSwgeDroidBeacon
    //% inlineInputMode=external
    export function activateSwgeDroidBeaconDropDown(personality: Personality): void {
        return;
    }
    /**
     * SWGE Location Beacon
     * @param zone [1-7] set the location id for the beacon
     */
    //% blockId=swge_location_beacon block="SWGE Location Beacon| for zone: %zone"
    //% parts="bluetooth" advanced=true
    //% shim=bluetooth::activateSwgeLocationBeacon
    //% zone.min=1 zone.max=7 zone.defl=1
    //% inlineInputMode=external
    export function activateSwgeLocationBeacon(zone: number): void {
        return;
    }
    /**
     * SWGE Advanced Location Beacon
     * @param zone [1-7] set the location id for the beacon
     */
    //% blockId=swge_location_beacon_advanced block="SWGE Advanced Location Beacon| for zone: %zone| with reaction interval %react_interval| and minimum RSSI (dBm) of %rssi"
    //% parts="bluetooth" advanced=true
    //% shim=bluetooth::activateSwgeLocationBeaconAdvanced
    //% zone.min=1 zone.max=7 zone.defl=1
    //% react_interval.min=0 react_interval.max=255 react_interval.defl=2
    //% rssi.min=-128 rssi.max=0 rssi.defl=-90
    //% inlineInputMode=external
    export function activateSwgeLocationBeaconAdvanced(zone: number, react_interval: number, rssi: number): void {
        return;
    }
    /**
     * SWGE Droid Beacon
     * @param personality [0-7] set the personality of the droid
     */
    //% blockId=swge_droid_beacon block="SWGE Droid Beacon| with personality: %personality"
    //% parts="bluetooth" advanced=true
    //% shim=bluetooth::activateSwgeDroidBeacon
    //% personality.min=0 personality.max=255 personality.defl=1
    //% inlineInputMode=external
    export function activateSwgeDroidBeacon(personality: number): void {
        return;
    }
    /**
     * SWGE Generic Beacon
     * @param mfr_id [0-65535] the manufacturer's id
     * @param beacon_data string ; the beacon data
     */
    //% blockId=swge_generic_beacon block="SWGE Generic Beacon| with Manufacturer's ID: %mfr_id| and Beacon Data: %beacon_data"
    //% parts="bluetooth" advanced=true
    //% shim=bluetooth::activateGenericBeacon
    //% mfr_id.shadowOptions.toString=true
    //% beacon_data.shadowOptions.toString=true
    //% inlineInputMode=external
    //% mfr_id.defl="0x0183"
    //% beacon_data.defl="0x0A040102A601"
    export function activateGenericBeacon(mfr_id: string, beacon_data: string): void {
        return;
    }
    /**
     * SWGE Beacon
     * @param zone [1-7] set the location id for the beacon
     */
    //% blockId=swge_beacon block="SWGE Beacon for| Zone: %zone"
    //% parts="bluetooth"
    //% shim=bluetooth::activateSwgeBeacon
    //% zone.min=1 zone.max=7 zone.defl=1
    //% deprecated=true
    export function activateSwgeBeacon(zone: number): void {
        return;
    }
}
