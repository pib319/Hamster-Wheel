const int sensor = 2;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int sen = digitalRead(sensor);
  if (sen == 0)
  {
    Serial.print("No black line detected\n");
  }
  else
  {
    Serial.print("Black line detected!\n");
  }
  delay(500);
}