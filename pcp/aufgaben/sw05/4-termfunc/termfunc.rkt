#lang racket

; -(10a + 20b - 40c) - (-(7a - 14c) - (-(15b - 4c) - (27a - 5b)))

; a)
(define (calcterm a b c)
  (-
    (- (- (+ (* 10 a) (* 20 b)) (* 40 c)))
    (-
      (- (- (* 7 a) (* 14 c)))
        (-
          (- (- (* 15 b) (* 4 c)))
          (- (* 27 a) (* 5 b))))))

; b)
; -(10a + 20b - 40c) - (-(7a - 14c) - (-(15b - 4c) - (27a - 5b)))
; = -10a - 20b + 40c - (-7a + 14c - (-15b + 4c - 27a + 5b))
; = -10a - 20b + 40c - (-7a + 14c + 15b - 4c + 27a - 5b)
; = -10a - 20b + 40c + 7a - 14c - 15b + 4c - 27a + 5b
; = -30a - 30b + 30c
(define (calcterm-simple a b c)
  (+
    (-
      (- (* 30 a))
      (* 30 b))
    (* 30 c)))

; 0
(calcterm 1 2 3)
(calcterm-simple 1 2 3)

; 60
(calcterm 2 5 9)
(calcterm-simple 2 5 9)
