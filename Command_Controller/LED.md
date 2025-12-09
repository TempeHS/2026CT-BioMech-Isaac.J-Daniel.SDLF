the OLED screen is meant to show the powering on function of the device, a welcome screen and a simple logo, which in this case is just a simple smiley face
the code uses the u8g2 library to display yext and a drawing on the screen.
,
,
,
u8g2.setFont(u8g2_font_ncenB08_tr);
u8g2.drawStr(0, 15, "Powering on...");

u8g2.setFont(u8g2_font_ncenB14_tr);
u8g2.drawStr(0, 40, "Welcome!");
,
,
,
this code works by setting the font to a certain size, and then drawing it on the screen in a certain spot.
this code specifically shows "Powering on..." at the top left of the OLED screen, and below it in bigger
letters is "Welcome!". The next important part of the code is to draw the logo, which is the smiley face.
,
,
,
// Draw a circle for the face
u8g2.drawCircle(64, 32, 20);
// Eyes
u8g2.drawDisc(56, 28, 2);
u8g2.drawDisc(72, 28, 2);
// Smile
u8g2.drawArc(64, 34, 12, 150, 240);
,
,
,
