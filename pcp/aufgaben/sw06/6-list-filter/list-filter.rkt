#lang racket

(define (list-filter rel-op a-list value)
  (cond
    ((empty? a-list) empty)
    (else
      (cond
        ((rel-op (first a-list) value)
         (cons (first a-list)
               (list-filter rel-op (rest a-list) value)))
        (else (list-filter rel-op (rest a-list) value))))))

; a)
(list-filter eq? '(a b c d e) 'c)

; b)
(list-filter char=? '(#\a #\b #\c #\d #\e) #\c)

; c)
(list-filter string=? '("Cheese" "Steak" "Beer") "Steak")
