#include <Adafruit_NeoPixel.h>
#define PIN    6
#define N_LEDS 30
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
uint32_t gradient(int angle, int offset);
int currentAngle = 0;

void setup() {
  strip.begin();
}
void loop() {
  uint32_t colour = (gradient(currentAngle, 0) << 16) +
    (gradient(currentAngle, 120) << 8) +
    gradient(currentAngle, 240);
  for (uint16_t i = 0; i < N_LEDS; i++) {
    strip.setPixelColor(i, colour);
  }
  strip.show();
  currentAngle++;
  if (currentAngle > 359)
    currentAngle = 0;
  delay(1000);
}
uint32_t gradient(int angle, int offset) {
  angle += offset;
  if (angle > 359)
    angle -= 360;
  int min = 0;
  int max = 255;
  uint32_t amp = 0;
  if (angle < 60)
    amp = min + angle * (max - min) / 60;
  else if (angle >= 60 && angle < 180)
    amp = max;
  else if (angle >= 180 && angle < 240)
    amp = max - (angle - 180) * (max - min) / 60;
  else
    amp = min;
  return amp;
}

