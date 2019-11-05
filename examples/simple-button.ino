#include "ButtonHandler.h"

//inputs
#define BTN_PIN 10

ButtonHandler _button = ButtonHandler(true);
int _lastEvent = BH_EVENT_NONE;

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  unsigned int buttonEvent = _button.handle(digitalRead(BTN_PIN), millis());

  if(_lastEvent == BH_EVENT_NONE && buttonEvent == BH_EVENT_HOLD) {
    // change to holding, do stuff
  } else if(_lastEvent == BH_EVENT_HOLD && buttonEvent == BH_EVENT_NONE) {
    // release, stop doing stuff
  } else if(BH_EVENT_CLICK) {
    // normal click
  }
}
