/*
  Light Blue Bean program
  Nitcha Tothong
  nitchafa.me

*/

// checkout https://github.com/GreyGnome/PinChangeInt/search?utf8=%E2%9C%93&q=attachPinChangeInterrupt 
// for other possible interrupts

// PinChangeInt handles pin change interrupts
#include <PinChangeInt.h>
#define MAX_BEAN_SLEEP 0xFFFFFFFF

// bend sensor variables
int prevA0;
int currentA0;
int smoothedA0;
float smoothSpeed = 0.1;

//define pins
uint8_t state;
static uint8_t state_sleep = 0;   //wait for wake up pin (LCD clock)
static uint8_t state_textNeck = 1;  //transmit results
static uint8_t state_triggerMsg = 2; // fix posture
static uint8_t state_waitForFixedPosture = 3;    //wait for disconnect

uint8_t valClock;

//timers
unsigned long timer_read_acc = 0;   //interval for reading accelerometer
unsigned long timer_pinClock = 0;   //used to check if still hooked up

//LED
static uint8_t red = 255;
static uint8_t green = 255;
static uint8_t blue = 255;

//acceleration
int16_t y_raw = 0;
//AccelerationReading acceleration = {0, 0, 0};

bool isConnected = 0;

void setup() {
  state = state_sleep;
  Serial.begin(9600);
}


void loop() {
  if (state == state_sleep) {
    //reset variables
    Bean.setLed(0, 0, 0);

    // run pinChanged when something changes on A0
    // This is an external library, so you don't need the prefix "Bean"
    // attach interrupt before sleep, detach interrupt after wake
    attachPinChangeInterrupt(A0, wakeUpRoutine, RISING);
    Bean.sleep(MAX_BEAN_SLEEP);

    //upon wake up, assume in test mode
    detachPinChangeInterrupt(A0);
    state = state_textNeck;

    timer_pinClock = millis();
  }
  
  if (state == state_textNeck){
    
  }
  if (state == state_triggerMsg){
    
  }
  if (state == state_waitForFixedPosture){
    
  }

}