#include <Servo.h>

// ARDUINO DEFINITIONS -----------------------------------------------------------------------------
#define throttlePin  3  // throttle pin 3
#define brakePin     5  // braking pin
#define steeringPin  6  // steering pin
Servo esc;              // ESC decloration

// BUTTON DEFINITIONS -----------------------------------------------------------------------------
int throttleState = 0;   // work as a button, set to 0
int brakeState = 0;      // work as a button, set to 0


void setup()  {
  Serial.begin(115200);
  pinMode(throttlePin, INPUT); // Set our input pins as such
  pinMode(brakePin,    INPUT); // Set our input pins as such
  pinMode(steeringPin, INPUT); // Set our input pins as such
  esc.attach(9);               // ESC pin 9
}

void loop()
{
  int RC_chan1; // channel on RC receiver, throttle pin from Arduino
  int RC_chan2; // channel on RC receiver, braking pin from Arduino
  int RC_chan3; // channel on RC receiver, steering pin from Arduino


  RC_chan1 = pulseIn(throttlePin, HIGH, 20000);
  int throttleState = analogRead(throttlePin);
  Serial.print("Channel 1:");
  Serial.println(RC_chan1);

  RC_chan2 = pulseIn(brakePin, HIGH, 20000);
  int brakeState = analogRead(brakePin);
  Serial.print("Channel 2:");
  Serial.println(RC_chan2);

  RC_chan3 = pulseIn(steeringPin, HIGH, 20000);
  int steering = analogRead(steeringPin);

  steering = map(steering, 0, 1023, 0, 179);
  esc.write(steering);
  
  Serial.print("Channel 3:");
  Serial.println(RC_chan3);

  delay(100);
}








