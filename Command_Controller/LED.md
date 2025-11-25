the OLED screen is supposed to show general information about the device, such as it's battery, the updates on pairing mode and the powering on and off screen. It
 will also show the welcome screen.
When the command controller is powered on, the OLED screen will display a "powering on... welcome" message. After it is powered on, this message will dissapear.
,
,
,
display.begin()
  print: "powering on... welcome"
  display.clearDisplay()
,
,
,
This begins the display, and then stops it, after the device is turned on
If using Bluetooth: Show “Pairing…” when the module is discoverable. Show “Connected” when paired. Show “Disconnected” when not paired.

An analog pin can be uses to read the voltage via voltage divider, and this can be used by converting the reading into a percentage and the ndisplaying it as text
 next to a little battery icon. 