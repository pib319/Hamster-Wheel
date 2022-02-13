const int interval = 20;            // PWM frequency (1000/x)
unsigned long prevMillis_1 = 0;     // Stores last time cycle was updated
unsigned long prevMillis_2 = 0;     // Stores last time LED was updated
int pwmTime = 1;                    // Controls the pulse width duration
const int cycle = 2;                // How many intervals the pwmTime should remain constant
int onTime;                         // The pulse width
int ledState;;                      // State of the LED

void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);         // default LED for Arduino Uno Rev 3
  onTime = interval;                    // Set Pulse Width to full
  ledState = HIGH;                      // Set the LED to on
}

void loop() 
{
  // put your main code here, to run repeatedly:
  unsigned long curMillis = millis();   // millis() returns # of milliseconds sinced board started running.

  if (curMillis - prevMillis_1 >= (interval * cycle)) // If # of cycles is passed
  {
    prevMillis_1 = curMillis;     // reset timer

    if (onTime == 0) {            // If pulse is completely off
      pwmTime = 1;
    }
    if (onTime == interval) {     // If pulse is completely on    
      pwmTime = -1;
    }

    onTime = onTime + pwmTime;    // Set pulse width duration
  }

  // Toggle the LED
  if (curMillis - prevMillis_2 >= interval)
  {
    prevMillis_2 = curMillis;
    ledState = HIGH; 
  }
  if (curMillis - prevMillis_2 >= onTime)
  {
    ledState = LOW; 
  }
  digitalWrite(LED_BUILTIN, ledState);
}