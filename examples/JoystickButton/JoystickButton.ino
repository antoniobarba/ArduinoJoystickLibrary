// Simple example application that shows how to read four Arduino
// digital pins and map them to the USB Joystick library.
//
// Ground digital pins 9, 10, 11, and 12 to press the joystick 
// buttons 0, 1, 2, and 3.
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2015-11-20
//--------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(0x03, JOYSTICK_TYPE_GAMEPAD, 3, 0, false, false, false, false, false, false, false, false, false, false, false);
int buttons[3] = {2,3,8};
void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  //pinMode(11, INPUT_PULLUP);
  //pinMode(12, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.sendState();
}

// Last state of the button
int lastButtonState[3] = {0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < 3; index++)
  {
    int currentButtonState = !digitalRead(buttons[index]);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
}
