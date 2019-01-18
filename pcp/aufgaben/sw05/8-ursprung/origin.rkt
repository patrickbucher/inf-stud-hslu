#lang racket

(define-struct point (x y))
(define (orig-dist p)
  (sqrt
    (+
      (expt (point-x p) 2)
      (expt (point-y p) 2))))

(define p (make-point 4 3))
(orig-dist p)
