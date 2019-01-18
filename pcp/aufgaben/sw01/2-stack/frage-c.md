Eine clear-Operation könnte sinnvoll sein, ihre Implementierung würde aber nur
darin bestehen, den Stack-Index auf -1 zu setzen, sodass neue Einträge die
alten überschreiben. Die Zuweisung `myStack.index = -1` erledigt genau dies.
Die clear-Operation hätte höchstens den Vorteil, dass der Stack die
Lösch-Operation explizit anbietet, und dass die Implementierungsdetails (`index
= -1`) gekapselt werden.

Eine clear-Operation im Sinne von "alle Elemente löschen/auf 0 setzen" ist
nicht sinnvoll, da die Implementierung der anderen Operationen mit
uninitialisierten (bzw. vorbelegten) Elementen zurechtkommen.

Ich würde eine clear-Operation wie oben beschrieben umsetzen.
