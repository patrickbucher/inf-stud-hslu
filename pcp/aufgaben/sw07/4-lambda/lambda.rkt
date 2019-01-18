#lang racket

; a)
(define x 2)
(define y 5)

((lambda (x y)
   (+ (* 2 x) y))
 y x)

; (5 2) -> (+ (* 2 5) 2) -> 12

((lambda (a b)
   (+ (* 2 x) y))
 y x)

; (5 2) -> (+ (* 2 2) 5) -> 9

; b)
; Beim ersten Ausdruck werden die globalen Variablen folgendermassen den
; Parametern zugeordnet:
; y (5) -> x
; x (2) -> y
; Beim zweiten Ausdruck werden die Parameter ignoriert. Die Berechnung erfolgt
; anhand der globalen Variablen.
