#lang racket

(define-struct human (age sex thigh))
(define (b-length human)
  (-
    (cond
      ((string=? (human-sex human) "male") (+ 69.089 (* 2.238 (human-thigh human))))
      ((string=? (human-sex human) "female") (+ 61.412 (* 2.317 (human-thigh human)))))
    (cond
      ((> (human-age human) 30) (* (human-age human) 0.06))
      (else 0))))

(define susi (make-human 22 "female" 50))
(define josy (make-human 42 "female" 50))
(define hans (make-human 82 "male" 50))
(define sepp (make-human 22 "male" 50))

(b-length susi)
(b-length josy)
(b-length hans)
(b-length sepp)
