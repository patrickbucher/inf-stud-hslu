#lang racket

(define (delete item a-list)
  (cond
    ((empty? a-list) empty)
    ((eq? (first a-list) item) (delete item (rest a-list)))
    (else
      (cons (first a-list) (delete item (rest a-list))))))

(delete 3 (list 1 2 3 4)) ; '(1 2 4)
(delete 'c '(a b c d)) ; '(a b d)
(delete 'f '(a b c d)) ; '(a b c d)
(delete 'f empty) ; '()
(delete 'f (list 1 2 3 4)) ; '(1 2 3 4)
