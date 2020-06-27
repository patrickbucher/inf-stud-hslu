Hallo Daniel

Nach der letzten Besprechung habe ich zunächst die Modellkomponente `joint_detection` umgebaut, sodass die Modelle beim Aufstarten des Services einmal in den Speicher geladen werden, und nicht mehr für jede Prediction (sprich Gelenkextraktion). Ein Röntgenbild kann nun lokal in ca. 12, auf einem Server in ca. 6 statt der vorherigen knapp 25 Sekunden verarbeitet werden.

Die 290 Bilder waren in etwas weniger als einer Stunde verarbeitet. Ca. 40 Bilder konnten nicht verarbeitet werden. Die Ergebnisse habe ich mit den Daten aus der SCQM-Datenbank kombiniert und mit Pandas als CSV abgelegt, sodass die Evaluation offline erfolgen kann.

Bei der Evaluation habe ich eine _Global Accuracy_ und eine _By-Class Accuracy_ jeweils mit exakten Vergleichen und "Soft Matches" (d.h. +/- eine Klasse wird als Treffer interpretiert) vorgenommen. _Cohen's Kappa_ habe ich einmal auf Papier mit einem fiktiven Beispiel durchgespielt und dann ausprogrammiert. _Cohen's Quadratic Kappa_ konnte ich auch ermitteln. Zusätzlich habe ich einige Visualisierungen gemacht (Confusion Matrix und Histogramm), die jedoch mit der etwas geringen Datenmenge nicht viel Aussagekraft haben. Den Code für die Evaluation habe ich umfassend mit Unittests abgedeckt.

Den `orchestrator` habe ich einem Refactoring unterzogen, sodass der Code nun etwas besser verständlich und modulerar ist. Dazu habe ich einen End-to-End-Test in Go geschrieben, der mehrere Bilder nebenläufig verarbeiten lässt, und so überprüft, dass das Auseinanderhalten der Requests über den Correlation Identifier funktioniert.

Für die drei Modellkomponenten habe ich jeweils Unit- bzw. Integrationstests geschrieben. Diese laufen in einem Docker-Container, der die Container der Modellkomponenten jeweils um `pytest` erweitert, und zusätzlich den Testcode in den Container kopiert. Diese Tests prüfen teilweise die Korrektheit der Predictions (linke Hand als solche erkannt) bzw. deren Plausibilität (Gelenk erfolgreich extrahiert, Ratingen-Score im Bereich 0..5).

Zusätzlich habe ich mit Go ein einfaches Web-UI gemacht, das auch in meinem [Video](https://www.youtube.com/watch?v=jEYBe8fIt9U) zeige. (Mit Genehmigung von SCQM ist das Video ungelistet auf YouTube.)

Liebe Grüsse

Patrick
