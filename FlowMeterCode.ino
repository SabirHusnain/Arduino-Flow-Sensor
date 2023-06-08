volatile int frequency;
unsigned int l_hour;
unsigned char flowsensor = 2;
unsigned long currentTime;
unsigned long setupTime;

void myFlow ()
{
  frequency++;
}

void setup()
{
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH);
  Serial.begin(9600);
  attachInterrupt(0, myFlow, RISING);
  sei();
  currentTime = millis();
  setupTime = currentTime;
}

void loop ()
{
  currentTime = millis();
  if (currentTime >= (setupTime + 1000))
  {
    setupTime = currentTime;
    l_hour = (frequency * 60 / 7.5);
    Serial.println("CLock frequency: "+String(frequency));
    frequency = 0;
    Serial.print(l_hour, DEC);
    Serial.println(" L/hour");
  }
}
