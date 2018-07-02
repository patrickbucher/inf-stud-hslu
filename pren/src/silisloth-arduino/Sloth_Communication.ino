//This task updates the flags, so sillysloth is up to date;)

void TaskCommunication(void *pvParameters) {
  (void) pvParameters;

  Serial.begin(9600);

  for (;;) {
    if (Serial.available()) {
      int byteRead = 0;
      byteRead = Serial.read();

      if (!getHeight) {                                                       //Change state, if HeightFlag is not set.
        state = byteRead;
        if (state == 'S') {
          getHeight = true;
        }
        vTaskDelay(1);
      } else if (!gotHeight) {                                                //Listen for height!
        if ((byteRead != ';') && (byteRead >= '0') && (byteRead <= '9')) {
          heightMillis = (heightMillis * 10) + (byteRead - '0');              //Set height
        } else {
          calcHeight();                                                       //Calculate steps from absolut height
        }
        vTaskDelay(1);
      }
    }
  }
}
