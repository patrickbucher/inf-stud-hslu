#lang racket

(define my-phone-dir
  (list
    (list 'Adam 4711)
    (list 'Eva 4712)))
(provide my-phone-dir)

; a) Die Funktion add-entry hat Seiteneffekte, sodass die Aufrufe von look-at
; vorher und nachher möglicherweise andere Ergebnisse zurückliefern.

; b)
(define (look-at phone-dir name)
  (cond
    ((cons? phone-dir)
     (cond
       ((eqv? (first (first phone-dir)) name) (first (rest (first phone-dir))))
       (else (look-at (rest phone-dir) name))))
    (else #f)))
(provide look-at)

; c)
(define (add-entry name number)
  (set! my-phone-dir (cons (list name number) my-phone-dir)))
(provide add-entry)
