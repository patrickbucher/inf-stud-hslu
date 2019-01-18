Bei der C-Implementierung mit dem Array ergibt das Wiederverwenden eines
"geleerten" Stacks Sinn, da das zugrundeliegende Array viel Arbeitsspeicher
besetzt.

Bei der Java-Implementierung mit der verketteten Liste ist dies wenig sinnvoll.
Zwar kann die Referenz auf das erste Element einfach auf `null` gesetzt werden,
sodass der Garbage-Collector die Kette der unreferenzierten Elemente einfach
entsorgt; andererseits kann auch einfach ein neuer Stack Instanziiert werden,
der nur sehr wenig Arbeitsspeicher belegt, wobei der alte Stack auch früher
oder später vom Garbage Collector eingesammelt wird.

Ich würde auf die clear-Operation verzichten.
