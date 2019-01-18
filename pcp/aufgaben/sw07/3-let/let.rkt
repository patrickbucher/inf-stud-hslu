#lang racket

(define a 42)

; a)
(let ((a 1)
      (b (+ a 1))) ; b = 42 + 1
  b)
; Ausgabe: 43

(let* ((a 1)
       (b (+ a 1))) ; b = 1 + 1
  b)
; Ausgabe: 2

; b)
; Mit let werden zunächst alle Ausdrücke evaluiert, wonach ihre Rückgabewerte
; der Reihe nach den Variablen zugewiesen werden.
; Mit let* werden die Ausdrücke von links nach rechts/von oben nach unten
; ausgewertet und gleich einer Variablen zugewiesen.
