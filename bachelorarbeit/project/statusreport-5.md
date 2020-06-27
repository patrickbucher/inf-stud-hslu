Hallo Daniel

Seit der letzten Besprechung hatte ich zunächst an der Zwischenpräsentation gearbeitet. Diese hatte ich vorab als [Video](https://vimeo.com/409465787) aufgenommen, falls Zoom an der Zwischenpräsentation nicht funktionieren sollte. Zum Glück hat aber alles prima geklappt, sodass die Aufzeichnung nicht nötig, aber für mich eine gute Übung war.

Nach der Zwischenpräsentation habe ich zunächst noch einige Refactorings an meinem [Protoyp](https://github.com/patrickbucher/fake-x-ray) vorgenommen, v.a. im Concurrency-Bereich (kein Shared State mit Mutex/Semaphor mehr). Dies hat prima funktioniert, sodass ich mich anschliessend an die richtige Umsetzung machte.

Nach zwei intensiven Tagen hatte ich eine komplett lauffähige Version, die sich end-to-end testen lässt. Damit habe ich gleich die drei an der Präsentation gezeigten Röntgenbilder gescored, was zu einem für mich plausiblen Ergebnis führte.

Den Prediction-Code der ersten Projektphase konnte ich grösstenteils übernehmen. Nur beim Modell `ratingen_score` war ich wohl damals etwas vorschnell: Das Modell gibt kein one-hot-encoded Array zurück, sondern ein Array von Wahrscheinlichkeiten. Zudem brauchten die Bildausschnitte noch einen Preprocessing-Schritt, den ich dem Vorgängerprojekt entnehmen konnte. Nach diesen Änderungen funktionierte aber alles bestens.

Die Performance von `joint_detection` ist im Moment der Flaschenhals. Hier lade ich das entsprechende Modell (`mcp1`, `pip1`, usw.) jeweils für jede Prediction neu, was ca. 50% der Ausführungszeit in Anspruch nimmt. So dauert das Scoring einer kompletten Hand auf meinem Rechner (keine dedizierte Grafikkarte, kein CUDA) end-to-end ca. eine Minute, bei paralleler Ausführung (fünf `joint_detection`-Instanzen) ca. 25 Sekunden.

Diese Komponente muss ich also noch etwas umbauen, damit die Modelle nur einmal geladen werden. Alternativ könnte ich auch pro Gelenk einen Service hochfahren, der dann jeweils ein Modell lädt. So hätte man zehn kleine statt einen grossen Service. Der Nachteil wäre die umständlichere Konfiguration und Erweiterbarkeit.

Ich habe bereits das Web-Abstract geschrieben (siehe Anhang). Die Umsetzungsdetails, mit denen ich mich jetzt im letzten Monat des Projekts noch befassen werde, dürften kaum noch grössere Änderungen am Web-Abstract nach sich ziehen, zumal dieses Dokument mit maximal drei Seiten nicht in die Tiefe geht.

Liebe Grüsse

Patrick
