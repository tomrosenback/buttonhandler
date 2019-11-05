#include "ButtonHandler.h"

//inputs
#define BTN_PIN 10

ButtonHandler _button = ButtonHandler(true);

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  unsigned int buttonEvent = _button.handle(digitalRead(BTN_PIN), millis());

  switch (_buttonEvent) {
    case BH_EVENT_CLICK:
      // normal click
      break;
    case BH_EVENT_HOLD:
      // long click
      break;
    default:
      break;
  }
}
