Hallo Daniel

Nach der letzten Besprechung habe ich die Metriken Accuracy, Precision, Recall und F1-Score noch einmal recherchiert und einige Beispiele dazu gemacht. Anschliessend habe ich die Metriken implementiert und in meinen Evaluationsworkflow integriert. Anschliessend habe ich noch das das Vertrauensintervall für Cohen's Quadratic Kappa berechnet. Ich habe die Metriken jeweils auf die "strenge" und die "weiche" (Soft Matches) Confusion Matrix angewendet. (Dass die Soft Matches mit Vorsicht zu geniessen sind, habe ich dokumentiert.)

Weiter habe ich die Achsen bei der Evaluation und der Visualisierung vereinheitlicht, sodass die x-Achse die menschlich ermittelten Scores und die y-Achse die maschinellen Predictions darstellt.

Anschliessend habe ich v.a. an der Dokumentation gearbeitet, d.h. den grössten Teil der letzten zwei Wochen. Das Kapitel 5 (Realisierung) war dabei das Aufwändigste. Dabei habe ich noch kleinere Korrekturen am Code vorgenommen, wenn mir beim Dokumentieren Unschönheiten aufgefallen sind.

Das Web-Abstract habe ich noch einmal etwas überarbeitet (siehe Anhang). Auch habe ich noch TLS (mit einem selbst signierten Zertifikat) implementiert, damit wenigstens die Verbindung zum Test- und Demosystem abgesichert ist, wenn ich Röntgenbilder darauf verarbeiten lasse.

TODO: Evaluation, Ausblick

Nun arbeite ich am Abschluss des Berichts. Am Wochenende möchte ich bereits die Schlusskorrektur vornehmen und die Abgabe vorbereiten.

Liebe Grüsse

Patrick
