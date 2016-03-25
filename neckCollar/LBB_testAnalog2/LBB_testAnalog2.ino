int prevA0;
int smoothedA0;

float speed = 0.1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // get zeno smoothed A0
  smoothedA0 = prevA0 * (1 - speed) + analogRead(A0) * speed;
  Serial.println(smoothedA0);

  // map smoothedA0 to LED
  int mappedForLed = map(smoothedA0, 700, 1000, 0, 255);
  Bean.setLed(mappedForLed, 255 - mappedForLed, 0);  
  //Text neck posture (bend neck down) : close 1000 : red
  //fixing  posture (look up) : close to 700 : green

  // update for next loop
  prevA0 = smoothedA0;

  //  Bean.sleep(100);
}
