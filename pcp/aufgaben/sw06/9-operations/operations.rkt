#lang racket

; a)
(define (a-op a)
  (cond
    ((>= a 0) +)
    (else -)))
; Die Funktion gibt für alle a >= 0 die Plus-Operation und für alle a < 0 die Minus-Funktion zurück.

(a-op -2)
(a-op -1)
(a-op 0)
(a-op 1)
(a-op 2)

; b)
(define (abs-a-plus-b a b)
  (+ (if (>= a 0) a (* a -1))
     (if (>= b 0) b (* b -1))))

(abs-a-plus-b 3 5) ; 8
(abs-a-plus-b -3 5) ; 8
(abs-a-plus-b 3 -5) ; 8
(abs-a-plus-b -3 -5) ; 8

; c)
(define (abs-a-op-b a b op)
  (op (abs a)
      (abs b)))

(abs-a-op-b 3 5 +) ; 8
(abs-a-op-b -3 5 *) ; 15
(abs-a-op-b 3 -5 -) ; -2
(abs-a-op-b -3 -5 /) ; 3/5
