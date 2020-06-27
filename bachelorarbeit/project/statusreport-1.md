Hallo Daniel

Übers Wochenende konnte ich folgendes herausfinden:

1. Keras-Modell für Scoring
    - Der Code zum Trainieren eines Modells ist hier zu finden: https://github.com/janickrohrbach/arthritis-net/blob/master/deepxray_classification_weights_transfer_learning.ipynb
    - Die dazugehörigen Datenverzeichnisse sind auf dem Seantis-Server nicht auffindbar, d.h. das Modell ist nicht verfügbar.
    - Ich habe Kontakt mit Janick Rohrbach aufgenommen, und gefragt, ob er noch Daten dazu hätte. Er wies mich darauf hin, dass dieses Modell nicht das aktuelle sei. Er hätte zusätzlich zu dieser Bachelorarbeit noch eine Masterarbeit zu diesem Thema gemacht, die dann auch Basis für das publizierte Paper ("Bone Erosion Scoring") gewesen sei. Die Daten hierzu lägen auf einem Server der ZHAW. Er verwies mich auf seine Betreuerin Beate Sick, die ich sogleich per Email dafür angefragt habe.
    - Ich hoffe, dass ich diese Woche möglichst bald an die Daten herankomme.
2. tflearn-Modelle für Extraktion
    - Ich habe mir eine lokale Docker-Umgebung (Python 3.6) für Tensorflow/tflearn eingerichtet. Damit lässt sich nun einigermassen lokal arbeiten.
    - Das Modell body_part konnte ich mittlerweile mit tensorflow 0.12.1 und tflearn 0.2.1 ohne Fehler einlesen und erneut abspeichern. Die Modelldaten sind also nicht korrupt; dies ist die positive Meldung.
    - Für den Export ins SavedModel-Format, das sich dann auch in andere Formate konvertieren liesse, wird Das Modul tf.saved_model benötigt, das in Tensorflow 0.12.1 nicht zur Verfügung steht. Mit Tensorflow 1.15.0 steht es zur Verfügung ‒ damit lässt sich jedoch das Modell nicht einlesen (Fehler wie vom Freitag).
    - Ich versuche am Dienstag oder Mittwoch das Problem zusammen mit Tobias Reinhard zu lösen, und werde mögliche Alternativen mit ihm besprechen.
    - Mit dem zweiten Modell (joint_detection) habe ich mich noch nicht befasst; dies dürfte aber Analog zu body_part sein. (Das Format ist das gleiche.)

Ich werde mich bis Mittwochabend noch einmal melden. Mit den anderen besprochenen Aufgaben (Planung, Testkonzept, Projektmanagement, Wahl der Programmiersprache) habe ich mich bisher noch nicht befasst.

Liebe Grüsse
Patrick
