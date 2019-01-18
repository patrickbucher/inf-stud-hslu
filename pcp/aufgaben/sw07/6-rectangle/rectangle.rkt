#lang racket

(define rect-calc-list
  (list (lambda (a b) (* a b))
        (lambda (a b) (* 2 (+ a b)))))
(provide rect-calc-list)

(define (calc-a-list f a b)
  (begin
    (displayln ((first rect-calc-list) a b))
    (displayln ((first (rest rect-calc-list)) a b))
    (displayln "finished")))
(provide calc-a-list)
