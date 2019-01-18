#lang racket

(define-struct rectangle (l w))
(define (diag rect)
  (sqrt (+ (expt (rectangle-l rect) 2)
           (expt (rectangle-w rect) 2))))

(define r (make-rectangle 3 4))
(diag r)
; 5 = sqrt(3² + 4²)
