#lang racket

(define a-list (list (list 1 2 3) (list 1 2) (list 1 2 3 4)))

((lambda (l)
   (list
     (cons 0 (car l))
     (cons 0 (cdar l))
     (cons 0 (cddar l))))
 a-list)

; Die Lösung funktioniert nur mit dieser spezifischen Listenstruktur (Liste aus
; drei Listen). Eine allgemeine Lösung müsste rekursiv sein, was mit
; Lambda-Ausdrücken nicht funktioniert.
