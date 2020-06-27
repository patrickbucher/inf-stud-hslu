Im Projekt DeepXRay geht es um die automatische Bewertung von Gelenken, die durch rheumatoide Arthritis geschädigt sind.

Die rheumatoide Arthritis ist eine Autoimmunerkrankung, bei der Gelenke durch chronische Entzündungen irreversibel geschädigt werden.

Die Erosion des Gelenkgewebes wird von medizinischem Fachpersonal auf Basis von Röntgenaufnahmen mit der _Ratingen-Score_ eingeschätzt.

Mithilfe dieser Score kann der Krankheitsverlauf an verschiedenen Körperteilen nachverfolgt werden.

Dieser manuelle Vorgang ist zeitaufwändig, was umfassende medizinische Langzeitstudien erschwert.

Im Rahmen des Projekts DeepXRay soll der Vorgang des Scorings automatisiert werden.

Hierzu kommen Machine-Learning-Modelle zum Einsatz, die bei der seantis GmbH und im Rahmen einer Bachelorarbeit an der ZHAW entwickelt worden sind.

Im Rahmen der vorliegenden Bachelorarbeit werden diese Modelle zu einem Web-Service kombiniert.

Dieser Web-Service bietet eine API an, über welche sich DeepXRay einfach in bestehende Anwendungen integrieren lässt.

Das Scoring der Gelenke erfolgt damit in Sekundenschnelle.

Ausserdem können die Scoring-Ergebnisse in konstanter Qualität geliefert werden, was bei der manuellen Einschätzung nicht immer der Fall ist.

Um diese Performance erreichen zu können, ist eine Architektur nötig, die das nebenläufige Ausführen der Komponenten ermöglicht.

Die Kommunikation zwischen den Komponenten erfolgt über eine Message-Queue, wodurch die parallele Abarbeitung von Röntgenbildern ermöglich wird.

Die Anwendung kann so beliebig verteilt und skaliert werden.

DeepXRay soll dabei helfen, Therapiemassnahmen für die rheumatoide Arthritis zu verbessern.
