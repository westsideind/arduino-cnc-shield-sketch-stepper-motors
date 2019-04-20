
// Arduino CNC Shield Expansion Board V3 +UNO R3 Board

//Define the pins on the board for each X, Y, Z pins

#define enable 8  // Pin 8 on UNO (Enable stepper)

#define xDir   5  // X Axis Direction Pin
#define xStep  2  // X Axis Step Pin

#define yDir   6  // Y Axis Direction Pin
#define yStep  3  // Y Axis Step Pin

#define zDir   7  // Z Axis Direction Pin
#define zStep  4  // Z Axis Step Pin

//Setp up the number of steps and the delay between the pulses
int steps = 200;      // Number of steps for the stepper 1.8 step angle for one revolution
int stepDelayX = 700;     //Delay between each pulse uS og30 - Change this if your stepper motor isn't moving and just making a noise (try 200-700)
int stepDelayY = 500;     //Delay between each pulse uS og30 - Change this if your stepper motor isn't moving and just making a noise (try 200-700)
int stepDelayZ = 500;     //Delay between each pulse uS og30 - Change this if your stepper motor isn't moving and just making a noise (try 200-700)

void step(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin, dir);
  delay(100);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds (stepDelayX);
    digitalWrite (stepperPin, LOW);
    delayMicroseconds (stepDelayX);

    digitalWrite(stepperPin, HIGH);
    delayMicroseconds (stepDelayY);
    digitalWrite (stepperPin, LOW);
    delayMicroseconds (stepDelayY);

    digitalWrite(stepperPin, HIGH);
    delayMicroseconds (stepDelayZ);
    digitalWrite (stepperPin, LOW);
    delayMicroseconds (stepDelayZ);
  }


}


void setup() {
  pinMode(xDir, OUTPUT); pinMode(xStep, OUTPUT); //setup the X Direction and X steps
  pinMode(yDir, OUTPUT); pinMode(yStep, OUTPUT); //setup the Y Direction and Y steps
  pinMode(zDir, OUTPUT); pinMode(zStep, OUTPUT); //setup the Z Direction and Z steps
  pinMode(enable, OUTPUT);
  digitalWrite(enable, LOW);



}

// Run the loop - use "false" for rotation of the stepper in the Clockwise direction, use "true" for counter clock wise
//
void loop() {
  step(false, xDir, xStep, 1000);  // X Axis Roate Clockwise
  delay(1000);
  step(true, xDir, xStep, 1000);  // X Axis Rotate Counter-Clockwise
  delay(1000);
  step(false, zDir, zStep, 1000);  // X Axis Roate Clockwise
  delay(1000);
  step(true, zDir, zStep, 1000);  // X Axis Rotate Counter-Clockwise
  delay(1000);

  
}
