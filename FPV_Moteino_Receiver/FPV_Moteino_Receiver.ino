#include <RFM12B.h>
#include <avr\sleep.h>
#include <avr\delay.h>
#include <LowPower.h>

// MOTEINO DEFINITIONS -----------------------------------------------------------------------------
#define NETWORKID         100  //what network this node is on
#define NODEID              2  //this node's ID, should be unique among nodes on this NETWORKID
#define GATEWAYID           1  //central node to report data to
#define KEY "ABCDABCDABCDABCD" //(16 bytes of your choice - keep the same on all encrypted nodes)
#define SERIAL_BAUD    115200

RFM12B radio;



// SERVO DEFINITIONS -----------------------------------------------------------------------------
#include <Servo.h>
Servo esc;
int throttlePin = 0;

void setup() {

  radio.Initialize(NODEID, RF12_915MHZ, NETWORKID);
  radio.Encrypt((uint8_t*)KEY);
  Serial.begin(SERIAL_BAUD);
  pinMode(LED, OUTPUT);
  Serial.println("Listening for LED blink/pulse/stop requests...\n");
  handleRequest(mode, theSpeed);
  Serial.println();

  
  esc.attach(9);
}

void loop()
{
  int throttle = analogRead(throttlePin);
  throttle = map(throttle, 0, 1023, 0, 179);
  esc.write(throttle);
}
