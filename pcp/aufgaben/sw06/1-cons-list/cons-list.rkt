#lang racket

(provide couple)
; '(("Adam" "Eva") ("Paul" "Paula"))
(define couple (list
                 (cons "Adam" (cons "Eva" empty))
                 (cons "Paul" (cons "Paula" empty))))

(provide spec-list)
; '(1 (2 3 (5 7) 9))
(define spec-list (list 1 (list 2 3 (list 5 7) 9)))

; a)
(rest (first couple)) ; '("Eva")
(first (rest couple)) ; '("Paul" "Paula")
(rest (rest couple)) ; '()
(first (first (rest couple))) ; "Paul"
(rest (first (rest couple))) ; '()
(cons? (rest (rest couple))) ; #f

; b)
(first (rest (first (rest (rest (first (rest spec-list)))))))
