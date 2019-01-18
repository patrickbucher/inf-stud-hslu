#lang racket

; a)
; Die Funktion liefert das letzte Element einer Liste zurück.
(define (f liste)
  (if (empty? list)
      empty
      (if (empty? (rest liste))
          (first liste)
          (f (rest liste)))))

(f '(1 2 3 4 5))
(f '(a b c d e))

; b)
; Die Funktion findet den grössten Wert in der Liste.
(define (g liste)
  (cond
    ((empty? liste) empty)
    ((empty? (rest liste)) (first liste))
    (else
      (if (> (first liste) (g (rest liste)))
          (first liste)
          (g (rest liste))))))

(g '(6 5 7 4 8 3))
