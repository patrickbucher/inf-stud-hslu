#include <Arduino_FreeRTOS.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

//Motor
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *drive = AFMS.getMotor(1);
Adafruit_DCMotor *airPump = AFMS.getMotor(2);
Adafruit_StepperMotor *stepper = AFMS.getStepper(200, 2);

//Communication constants/States
const char WAIT = 'W';
const char START = 'G';         //G for Go
const char STOP = 'S';          //S for Stop
const char SLOW = 'D';          //D for Deaccelerate
const char END = 'H';
const char EMERGENCYSTOP = 'E';

//Intern Constants/States
const char ACCELERATE = '0';
const char DRIVE = '1';
const char DRIVESLOW = '2';
const char STEPDOWN = '3';
const char STEPUP = '4';
const char GRAB = '5';
const char LOSLAH = '6';

//Variables
int state;                  //Current state
int heightMillis;           //Distance in z direction [mm]
int heightSteps;            //Distance in z direction in steps [1.8°]
boolean getHeight;          //Listen for height
boolean gotHeight;          //Got height
boolean load;               //Got load
boolean loadDelivered;      

//Define tasks
void TaskCommunication(void *pvParameters);
void TaskStateMachine(void *pvParameters);

void setup() {

  AFMS.begin();
  TWBR = ((F_CPU / 400000l) - 16) / 2;    //Set I2C-frequency 400kHz
  airPump->setSpeed(255);                 //Set speed for airpumps
  stepper->setSpeed(600);                 //Set stepper speed (400)
  stepper->step(1, FORWARD, DOUBLE);      //Makes the stepper stay
  pinMode(10, OUTPUT);                    //Pins 9 & 10 are going to the motorshield's servo output
  digitalWrite(9, LOW);

  state = 'W';                            //Go in WAIT-state
  heightMillis = 0;
  heightSteps = 0;
  getHeight = false;                      //Listen for height if true
  gotHeight = false;                      
  load = false;
  loadDelivered = false;


  xTaskCreate(
    TaskCommunication
    , (const portCHAR *)"Communication"     //Taskname
    , 128                                   //Stack size
    , NULL
    , 2                                     //Priority
    , NULL);

  xTaskCreate(
    TaskStateMachine
    , (const portCHAR *)"State Machine"     //Taskname
    , 128                                   //Stack size
    , NULL
    , 3                                     //Priority
    , NULL);

}

void loop() {}
