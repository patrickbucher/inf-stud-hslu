Hallo Daniel

Hier ist mein Statusreport seit der letzten Besprechung.

Seit der letzten Besprechung habe ich mich vor allem mit der Architektur und der Evaluation beschäftigt.

Bei der Architektur habe ich mich in das Standardwerk [Enterprise Integration Patterns](https://www.enterpriseintegrationpatterns.com/patterns/messaging/) eingearbeitet und die vier grundlegenden Integrationsvarianten (_File Transfer_, _Shared Database_, _Remote Procedure Call_ und _Messaging_) zusammenfassend mit ihren Vor- und Nachteilen dokumentiert. Als weitere Integrationsvariante habe ich HTTP (REST) betrachtet, was beim Erscheinen von _Enterprise Integration Patterns_ noch weniger verbreitet war für Software-Integration.

Ich habe weiter vier Architekturvarianten ausgearbeitet. Diese sind erst teilweise grafisch aufbereitet (Komponenten- und Sequenzdiagramm). Das möchte ich bis zur Zwischenpräsentation noch abschliessen.

Da die Varianten darauf hinauslaufen, dass neben HTTP auch Messaging zum Einsatz kommt, habe ich mich in die Messaging-Lösungen ZeroMQ (low-level-Library) und RabbitMQ (high-level-Broker nach AMQP-Spezifikation) eingearbeitet und verschiedene Beispiele damit implementiert.

Bis zur Präsentation möchte ich einen Prototyp fertiggestellt haben, womit man textuelle Repräsentationen anstelle von Bildern End-to-End verarbeiten kann, um damit meinen Architekturvorschlag zu validieren.

Für die Evaluation habe ich zusammen mit Tobias Reinhard neuere Daten aus der SCQM-Datenbank extrahiert. Im Moment selektiere ich diese mithilfe eines interaktiven Skripts für Positiv- und Negativtests (unterschiedliche Körperteile), womit ich etwa zur Hälfte durch bin. Insgesamt dürften aus dem Prozess ca. 200 gescorte Röntgenbilder von linken Händen resultieren.

Weiter habe ich verschiedene Metriken aus [Evaluating Machine Learning Modells](https://proquest.tech.safaribooksonline.de/book/programming/machine-learning/9781492048756/firstchapter) angeschaut und im Bezug auf ihre Eignung für die verwendeten Modelle dokumentiert. Eine weitere Metrik aus dem [publizierten Paper](https://www.sciencedirect.com/science/article/pii/S0045790618329409) ist _Cohen's square Kappa_, die jedoch zwei Scores pro Gelenk benötigt.

Die Planung der dritten und letzten Phase ist noch ausstehend. Diese möchte ich nach der Zwischenpräsentation finalisieren.

Liebe Grüsse

Patrick
