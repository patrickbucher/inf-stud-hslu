# Ablauf

| Raspi                           | Befehl       | Richtung | Arduino                                   |
|---------------------------------|--------------|----------|-------------------------------------------|
| Startsignal erkennen            | `dc_start;`  | `→`      | Antriebsmotor starten                     |
|                                 |              |          | Anhalten über Würfel                      |
|                                 |              |          | Greifarm senken                           |
| Ultrachallsensor starten        | `us_start;`  | `←`      | Last greifen                              |
|                                 |              |          | Last anheben, weiterfahren                |
| Kamera starten                  |              |          |                                           |
| Zielfeld gesehen                | `dc_slow;`   | `→`      | verlangsamen                              |
| Position über Zielfeld erreicht | `sm_down=h;` | `→`      | anhalten, Last um `h` Millimeter absenken |
|                                 |              |          | Greifer lösen, anheben, weiterfahren      |
| kritische Nähe vom Mast erkannt | `dc_slow;`   | `→`      | verlangsamen                              |
| Endtaster betätigt              | `dc_stop;`   | `→`      | anhalten                                  |

