const int l_sensor = 2; // Left IR Sensor
const int r_sensor = 3; // Right IR Sensor
const double halfCircum = 349.633; // Half circumference of wheel in mm.
double distance = 0; // Total distance the hamster has ran. 
double distIn = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(l_sensor, INPUT);
  pinMode(r_sensor, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int l_sen_in = digitalRead(l_sensor);
  int r_sen_in = digitalRead(r_sensor);

  if ((l_sen_in == 1 && r_sen_in == 0) || (l_sen_in == 0 && r_sen_in == 1))
  {
    distance = distance + halfCircum;         // Add to the total distance ran
    distIn = distance * 0.0393701;
    Serial.print(distIn);                     // Output total distance to the terminal
    Serial.print(" inches \n");
    delay(250);                               // Wait so multiple readings don't get read at once
  }
}