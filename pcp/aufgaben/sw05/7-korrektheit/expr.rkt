#lang racket

(define a 2)
(define b 2)

(* (cond ((> a b) a)
         ((< a b) b)
         (else -1))
   (+ a 1))

; a)
; Es handelt sich um einen korrekten Scheme-Ausdruck. cont liefert einen Wert
; zurück, der wiederum als Operand dient.

; b)
; 1.
; (define a 3)
; (define b 5)
; 30
;
; 2.
; (define a 5)
; (define b 3)
; 30
;
; 3.
; (define a 2)
; (define b 2)
; -3
