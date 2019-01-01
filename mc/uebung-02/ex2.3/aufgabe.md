Schreiben Sie eine Funktion `int *row(int from, int to, int step)`, die eine
Reihe beginnent mit der Zahl `from` bis (exklusiv) `to` mit der Schrittweite
`step` erzeugt.

Beispiel: Für den Aufruf

    row(1, 10, 3);

soll das Ergebnis

    [1, 4, 7]

lauten.

Ist eines der drei Argumente negativ, oder ist `to` nicht grösser als `from`,
soll die Funktion `NULL` zurückgeben. Die Reihe soll mit dem Pseudo-Eintrag -1
terminiert werden.
