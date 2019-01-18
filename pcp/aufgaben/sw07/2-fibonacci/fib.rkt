#lang racket

(define (fib n)
  (cond
    ((or (= n 0) (= n 1)) n)
    (else (+ (fib (- n 1))
             (fib (- n 2))))))

; a)
(define (fib-acc n)
  (local
    (
     (define (fib n prev acc)
       (cond
         ((or (= n 0) (= n 1)) acc)
         (else
           (fib (- n 1) acc (+ prev acc))))))
    (fib n 0 1)))

; b)
(define test-val 40)
(time (fib test-val))     ; 1662ms
(time (fib-acc test-val)) ;    1ms
