unsigned long previousMillis = 0;   // Stores last time LED was updated
const long interval = 1000;         // Interval at which to blink (milliseconds)
int ledState = LOW;                 // Setup initial state of the LED

void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ledState);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();   // millis() returns # of milliseconds sinced board started running.

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }
  /*
  Traditional Method, using delay() stops everything.

  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
  delay(100);                       // Wait for 1 second
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off
  delay(100);                       // Wait for 1 second
  */
}
