#lang racket

; a)
(/ 1 (+ 1 1))
; 1 : (1 + 1) = 1/2

; b)
(/ 1 (+ 1 (/ 1 (+ 1 1))))
; 1 : {1 + [1 : (1 + 1)]} = 2/3

; c)
(/ 1 (+ 1 (/ 1 (+ 1 (/ 1 (+ 1 1))))))
; 1 : [1 + (1 : {1 + [1 : (1 + 1)]})] = 3/5

; Die Lösungen werden exakt als Brüche dargestellt. Bei der Kontrolle mit
; Python lautete die Lösung bei c) hingegen 0.6000000000000001 (ungenau).
