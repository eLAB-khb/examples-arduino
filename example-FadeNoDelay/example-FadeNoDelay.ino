const int pinLED = 5;

const boolean UP = 0;
const boolean DOWN = 1;

int minPWM = 0;
int maxPWM = 255;

boolean fadeDirection = UP;
int fadeValue = 0;
int fadeIncrement = 5; // how smooth to fade?
int fadeInterval = 50; // how fast to increment?

unsigned long previousFadeMillis;

void setup()
{
  pinMode(pinLED, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousFadeMillis >= fadeInterval)
  {
    if (fadeDirection == UP)
    {
      fadeValue = fadeValue + fadeIncrement;
      if (fadeValue >= maxPWM)
      {
        fadeValue = maxPWM;
        fadeDirection = DOWN;
      }
    }
    else
    {
      fadeValue = fadeValue - fadeIncrement;
      if (fadeValue <= minPWM)
      {
        fadeValue = minPWM;
        fadeDirection = UP;
      }
    }

    analogWrite(pinLED, fadeValue);

    previousFadeMillis = currentMillis;
  }
}
