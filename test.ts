basic.showString("X")

input.onButtonPressed(Button.A, () => {
    bluetooth.activateSwgeLocationBeacon(1)
    basic.showString("A")
})

input.onButtonPressed(Button.B, () => {
    bluetooth.activateGenericBeacon(0x0183, "HELLO");
    basic.showString("B")
})
