
//All functions are defined here..

//Drive functions
void driveForward() {
  drive->run(BACKWARD);
  drive->setSpeed(255);       //Max Speed 205 current max speed
  vTaskDelay(1);
}

void driveSlowForward() {
  drive->run(BACKWARD);
  drive->setSpeed(200);       //Half Speed
  vTaskDelay(1);
}

void driveSlowEnd() {
  drive->run(BACKWARD);
  drive->setSpeed(100);
  vTaskDelay(1);
}
void driveBackward() {
  drive->run(FORWARD);
  drive->setSpeed(235);
  vTaskDelay(1);
}

void accelerate() {
  drive->setSpeed(0);
  drive->run(BACKWARD);
  for (int i = 0; i < 204; i++) {
    drive->setSpeed(i);
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void deAccelerate() {
  for (int i = 0; i > 127; i--) {
    drive->setSpeed(i);
    vTaskDelay(5 / portTICK_PERIOD_MS);
  }
}


void stopDrive() {
  drive->run(RELEASE);
  drive->setSpeed(0);
  vTaskDelay(1);

}

//Communication function
void feedBack() {
  //Serial.write('L');        //Writes a 'L' for got Load
  Serial.print('L');
  vTaskDelay(1);
}


void calcHeight() {

  //Calculating height to steps and start stepper motor
  if (heightMillis > 165) {
    heightSteps = (int)((heightMillis - 140) * 7.64);
  }

  getHeight = false;
  gotHeight = false;        //Listen for height again when over target
  state = STEPDOWN;         //Go to state 2 for stepping down

  vTaskDelay(1);
}


//Airpumpfunction
void prePump() {
  airPump->run(FORWARD);
}
void stopPump() {
  airPump->run(RELEASE);
}
void pump() {
  airPump->run(FORWARD);
  vTaskDelay(14500 / portTICK_PERIOD_MS);
  airPump->run(RELEASE);
}

void releaseGrabber() {
  digitalWrite(10, HIGH);
  vTaskDelay(4000 / portTICK_PERIOD_MS);    //Let the air out (open magnetic valve for 3s)
  digitalWrite(10, LOW);

}

void stepUp(int height) {
  int steps = height;
  stepper->step(steps, BACKWARD, DOUBLE);
}

void stepDown(int height) {
  int steps = height;
  stepper->step(steps, FORWARD, DOUBLE);
}








