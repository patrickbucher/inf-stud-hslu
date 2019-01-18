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

(define (dividable? a b)
  (= 0 (remainder a b)))

(list-filter dividable? '(1 2 3 4 5 6 7 8 9) 2) ; '(2 4 6 8)
