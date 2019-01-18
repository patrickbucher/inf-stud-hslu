#lang racket

(define (toll total-weight)
  (cond
    ((not (number? total-weight)) "Eingabe muss Zahl sein!")
    ((<= total-weight 0) "Zahl muss größer 0 sein!")
    ((<= total-weight 1000) 20)
    ((<= total-weight 2000) 30)
    ((<= total-weight 5000) 50)
    ((<= total-weight 10000) 100)
    (else 250)))

(toll 40000)

; a)
; 1. Klausel: überprüfen, ob der Parameter nicht numerisch ist
; 2. Klausel: überprüfen, ob der Parameter negativ ist

; b)
; cond beendet, sobald eine Klausel ausgeführt wurde. Die weiteren Klauseln
; gehen davon aus, dass die beiden ersten Klauseln nicht zutreffen. Es wird
; impliziert, dass der Parameter ein positiver numerischer Wert ist.

; c)
; Beispiel bezogen auf den Wert: Für Zahlen > 10000 ist die Klausel-Reihenfolge
; beliebig.
; Beispiel bezogen auf die Logik: Für Klauseln, die einen geschlossenen
; Wertebereich oder exakte Werte prüfen. 

(define (comment mark)
  (cond
    ((= mark 4) "genügend")
    ((= mark 5) "gut")
    ((and (< mark 4) (>= mark 1)) "ungenügend")
    ((= mark 6) "sehr gut")))

(comment 6)
(comment 5)
(comment 4)
(comment 3)
(comment 2)
(comment 1)
