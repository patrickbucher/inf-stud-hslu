Hallo Daniel

Hier ist mein Statusreport über die letzten zwei Wochen:

tl;dr: Alle Modelle sind bereit, und ich konnte mit ihnen Predictions machen.

Mit dem Modell `body_part`, das ich vorher bereits laden konnte, konnte ich jetzt eine Prediction machen. Die Inputs und Outputs habe ich entsprechend dokumentiert. Dieses Modell erkennt das Körperteil auf einen Röntgenbild (Hand, Fuss, Becken usw.). Ich werde es jedoch nur für die Input-Validierung einsetzen, um zu prüfen, ob ein Röntenbild eine linke Hand zeigt. Mit anderen Körperteilen können die nachfolgenden Modelle nämlich nicht umgehen.

Das Modell `joint_detection` ist eigentlich eine Serie von Modellen; pro Gelenk gibt es eine Modelldatei, sprich zehn Modelle. Ich konnte diese Modelle stichprobenartig (d.h. bisher mit zwei, drei Gelenken getestet) einlesen und eine Prediction damit durchführen. Die Inputs/Outputs habe ich mir notiert und muss ich noch sauber dokumentieren.

Beim Modell `rau_score`, das ich neu als `ratingen_score` bezeichne (der Unterschied ist in der Dokumentation beschrieben), hatte ich am meisten zu tun. Auf Basis der [Bachelorarbeit von Janick Rohrbach](https://github.com/janickrohrbach/arthritis-net) konnte ich die Testdaten neu aus den Rohdaten generieren und das ganze neu trainieren.

Dies schien auf dem Machine-Learning-Sytem bei Seantis zuerst Tage zu dauern, zumal es ein Problem mit dem CUDA-Setup gab, und der Workload auf der CPU lief. Hier wäre ein Neustart des Systems nötig gewesen, den ich aufgrund der Festplattenverschlüsselung nur vor Ort machen kann. Da bei uns in der Firma Home Office verordnet worden ist, konnte ich dies nicht zeitnah durchführen. (Mittlerweile habe ich das nachgeholt, und CUDA wäre darauf wieder einsatzbereit.)

So bin ich auf eine GPU-Instanz bei Exoscale ausgewichen, wo das Modell innert ca. zwei Stunden trainiert und exportiert war. Die Evaluation hat eine Performance von ca. 70% ergeben, was den Angaben in der Bachelorarbeit von Janick Rohrbach entspricht. Eine Prediction konnte ich damit auch bereits ausführen. Auch hier muss ich noch die Inputs/Outputs dokumentieren.

Für die Phase 1, die am 31. März endet, muss ich also die Dokumentation noch ergänzen, mögliche Testfälle beschreiben und die Phase 2 planen.

Liebe Grüsse

Patrick

PS: Ich gehe davon aus, dass die morgige Besprechung wieder per Skype stattfinden wird, richtig?
