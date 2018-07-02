
//StateMachine =)
//
//

void TaskStateMachine(void *pvParameters) {
  (void) pvParameters;

  for (;;) {

    switch (state) {
      //External states set by raspi-------------------
      case START:
        driveSlowForward();        //Drive (external command)
        prePump();
        vTaskDelay(1);
        break;
      case STOP:                   //Stop (external)
        stopPump();
        stopDrive();
        break;
      case SLOW:
        deAccelerate();
        state = DRIVESLOW;
        vTaskDelay(1);
        break;
      case END:
        stopDrive();
        loadDelivered = false;
        //---------Test                                 //Wait 3 seconds, drive back to start
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        driveBackward();
        vTaskDelay(15000 / portTICK_PERIOD_MS);
        stopDrive();
      //---------Test
        state = 'W';
      //exit(EXIT_SUCCESS);

      //Internal states----------------------
      case WAIT:
        //Do nothing..
        break;
      case ACCELERATE:
        accelerate();
        state = DRIVE;
        break;
      case DRIVE:
        driveForward();
        break;
      case DRIVESLOW:
        if (!loadDelivered) {
          driveSlowForward();
        } else {
          driveSlowEnd();
        }
        break;
      case STEPDOWN:
        stepDown(heightSteps);
        if (load) {               //If load is grabbed
          state = LOSLAH;         //Release
        } else {
          state = GRAB;          //else grab load
        }
        break;
      case STEPUP:
        stepUp(heightSteps);
        heightMillis = 0;
        state = ACCELERATE;
        break;
      case GRAB:
        pump();
        load = true;
        getHeight = false;
        feedBack();
        state = STEPUP;
        break;
      case LOSLAH:
        releaseGrabber();
        load = false;
        loadDelivered = true;
        feedBack();
        state = STEPUP;
        break;

      default:
        state = 'W';
    }
    vTaskDelay(1);
  }
}

