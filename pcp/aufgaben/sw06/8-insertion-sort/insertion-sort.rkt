#lang racket

(define (sort-a-list num-list cmp-func)
  (cond
    ((empty? num-list) empty)
    (else (insert (first num-list)
                  (sort-a-list (rest num-list) cmp-func) cmp-func))))

(define (insert item a-list cmp-func)
  (cond
    ((empty? a-list) (list item))
    ((cmp-func item (first a-list)) (cons item  a-list))
    (else (cons (first a-list) (insert item (rest a-list) cmp-func)))))

(define numbers '(6 5 8 9 7 0 4 2 3 1))
(sort-a-list numbers <=) ; ascending
(sort-a-list numbers >=) ; descending

(define strings '("Alfred" "Xaver" "Fritz" "Bernhard"))
(sort-a-list strings string<?)
