#include <Arduino.h>

const int LED_PIN = LED_BUILTIN;
const int BREATH_DELAY = 5; // Controls breathing speed
const int HOLD_TIME = 200;  // Time to hold at peak brightness

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void breathe()
{
  // Fade in
  for (int brightness = 0; brightness < 255; brightness += 2)
  {
    analogWrite(LED_PIN, brightness);
    delay(BREATH_DELAY);
  }

  // Hold at peak
  delay(HOLD_TIME);

  // Fade out
  for (int brightness = 255; brightness >= 0; brightness -= 2)
  {
    analogWrite(LED_PIN, brightness);
    delay(BREATH_DELAY);
  }

  // Hold at off
  delay(HOLD_TIME);
}

void loop()
{
  breathe();
}
