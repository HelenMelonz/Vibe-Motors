@@ -0,0 +1,40 @@
/*
Adafruit Arduino - Lesson 13. DC Motor
*/
 
 
const int motorPin[3] = {6,9,10}; // array declaring which pins to use
int motor = 0; // index into motorPin 
const int speed = 200; // declaring constantly go at 200 speed
const int turnOff = 0; //turn off motor

void setup() 
{ 
  for (motor = 0; motor<=2; motor++) //for loop
    pinMode(motorPin[motor], OUTPUT); // declaring which pins are output pins
  Serial.begin(9600); // turn on serial
  while (! Serial); // do nothing until serial is ready
  Serial.println("Which Motor; 0, 1 or 2"); // print message in serial
} 
 
 
void loop() 
{ 
  int action[3]; //there is an action for each motor
  int a; // index into action
    
  if (Serial.available()) //wait until someone has typed something
  {
    motor = Serial.parseInt(); //turn whatever was typed into an integer that represents which motor to us
    for (a=0; a<=2 ; a++) { //cycle through actions for each motor
      if ( a==motor )      // is this motor to be turned on
        action[a]=speed;    // if so, set speed
      else         
        action[a]=turnOff; // otherwise set action to turn off 
      analogWrite(motorPin[a], action[a]); //turn requested motor on at speed 200 and turn other two motors off
    }
  }
} 

