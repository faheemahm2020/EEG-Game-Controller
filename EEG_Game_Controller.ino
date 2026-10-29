#include <Keyboard.h>

#define SIGNAL_PIN A0

#define JUMP_KEY KEY_UP_ARROW
#define DUCK_KEY KEY_DOWN_ARROW

const int THRESHOLD = 120;      // Tune for your setup
const int SAMPLE_DELAY = 2;

bool active = false;
bool ducking = false;

unsigned long startTime = 0;
unsigned long lastTrigger = 0;

void setup()
{
  Serial.begin(115200);
  Keyboard.begin();
}

void loop()
{
  static float baseline = 512;

  int raw = analogRead(SIGNAL_PIN);

  baseline = baseline * 0.995 + raw * 0.005;

  int value = abs(raw - baseline);

  Serial.println(value);

  unsigned long now = millis();

  if(value > THRESHOLD)
  {
      if(!active)
      {
          active = true;
          startTime = now;
      }

      if(!ducking && (now - startTime > 700))
      {
          Keyboard.press(DUCK_KEY);
          ducking = true;
      }
  }
  else
  {
      if(active)
      {
          unsigned long duration = now - startTime;

          if(duration < 500 && (now-lastTrigger)>300)
          {
              Keyboard.press(JUMP_KEY);
              delay(25);
              Keyboard.release(JUMP_KEY);

              lastTrigger = now;
          }
      }

      active = false;

      if(ducking)
      {
          Keyboard.release(DUCK_KEY);
          ducking = false;
      }
  }

  delay(SAMPLE_DELAY);
}
