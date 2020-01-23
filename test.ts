basic.showString("X")

input.onButtonPressed(Button.A, () => {
    bluetooth.activateSwgeBeacon(1)
    basic.showString("O")
})

input.onButtonPressed(Button.B, () => {
    bluetooth.stopAdvertising();
    basic.showString("X")
})
