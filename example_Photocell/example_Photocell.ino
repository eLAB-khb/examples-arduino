int valuePhotocell;
int pinLED = 3;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  valuePhotocell = analogRead(A0);

  // ~ 200: daylight
  // ~ 600: covered

  int valueLED = map(valuePhotocell, 400, 600, 0, 255);
  valueLED = constrain(valueLED, 0, 255);

  analogWrite(pinLED, valueLED);

  Serial.print(valuePhotocell);
  Serial.print("  >  ");
  Serial.print(valueLED);
  Serial.print(" \t >  ");
  Serial.println();
}

