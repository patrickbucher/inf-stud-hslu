#lang racket

; a)
(define temperatur 40)
(cond
  ((> temperatur 35) "heiss")
  ((> temperatur 25) "warm")
  ((> temperatur 15) "mittel")
  (else "kalt"))

; Die Klauseln dürfen nicht vertauscht werden. Würde die dritte Klausel
; ("mittel") ganz nach oben geschoben, ergäbe das für 40 nicht mehr "heiss"
; sondern eben "mittel".

; b)
(define zahl 6)
(cond
  ((zero? (remainder zahl 2)) "durch 2 teilbar")
  ((zero? (remainder zahl 3)) "durch 3 teilbar")
  (else "weder durch 2 noch durch 3 teilbar"))

; Die Klauseln dürfen nicht vertauscht werden. Würde die zweite Klausel ("durch
; 3 teilbar") nach oben verschoben, ergäbe das für 6 nicht mehr "durch 2
; teilbar" sondern eben "durch 3 teilbar".
