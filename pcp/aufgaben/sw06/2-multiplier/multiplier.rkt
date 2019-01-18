#lang racket

(define (mult fact1 fact2)
  (* fact1 fact2))

(define (multiplier lst fact)
  (cond
    ((empty? lst) empty)
    (else
      (cons
        (mult (first lst) fact)
        (multiplier (rest lst) fact)))))

(define numbers '(1 2 3 4 5))
(multiplier numbers 2)
(multiplier numbers 3)
(multiplier numbers 4)
