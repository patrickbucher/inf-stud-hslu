#lang racket

(define (contains? item a-list)
  (cond
    ((empty? a-list) #f)
    ((eq? (first a-list) item) #t)
    (else (contains? item (rest a-list)))))

(contains? 'c '(a b c d)) ; true
(contains? 'f '(a b c d)) ; false
