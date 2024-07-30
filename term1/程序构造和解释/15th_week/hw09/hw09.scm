;;; Homework 09: Scheme List, Tail Recursion and Macro

;;; Required Problems

(define (make-change total biggest)
    (define (make-change-helper total biggest)
        (cond
            ((= total 0) '(()))
            ((or (< total 0) (= biggest 0)) '())
            (else
            (append
            (map (lambda (x) (cons biggest x))
                (make-change-helper (- total biggest) biggest))
            (make-change-helper total (- biggest 1))))))
    (make-change-helper total biggest)
)

(define (find n lst)
    (define (helper index lst)
        (if (= (car lst) n)
            index
            (helper (+ index 1) (cdr lst))
        )
    )
    (helper 0 lst)
)


(define (find-nest n sym)
    (define (helper lst so_far)
        ;(print `(lst = ,lst ) )
        (cond
            ((null? lst) nil)
            ((and (not (list? (car lst))) (= (car lst) n)) `(car ,so_far))
            ((list? (car lst)) (if (not (null? (helper (car lst) so_far))) (helper (car lst) `(car ,so_far)) (helper (cdr lst) `(cdr ,so_far))))
            (else  (helper (cdr lst) `(cdr ,so_far)))
        )
    )
    (helper (eval sym) sym)
)



(define-macro (my/or operands)
    (cond
        ((null? operands) #f)
        ((null? (cdr operands)) (car operands))
        (else
        `(let ((t ,(car operands)))
            (if t
                t
                (my/or ,(cdr operands)))))
    )
)

(define (call-helper args vals indices index result)
    (cond
        ((null? args) result)
        ((and (not (null? vals)) (= index (car indices)))
            (call-helper (cdr args) (cdr vals) (cdr indices) (+ index 1) (append result `(,(car vals))))
        )
        (else (call-helper (cdr args) vals indices (+ index 1) (append result `(,(car args)))))
    )
)

(define (arg-helper args vals indices index result)
    (cond
        ((null? args) result)
        ((and (not (null? vals)) (= index (car indices)))
            (arg-helper (cdr args) (cdr vals) (cdr indices) (+ index 1) result)
        )
        (else (arg-helper (cdr args) vals indices (+ index 1) (append result `(,(car args)))))
    )
)

(define-macro (k-curry fn args vals indices)
    `(lambda ,(arg-helper args vals indices 0 '()) ,(call-helper args vals indices 0 (list fn)) )
)

;(define-macro (let* bindings expr)
;    (cond
;        ((null? bindings) (car bindings))
;        ((null? (cdr bindings)) (car bindings))
;        (let ((car bindings)) ())
;        (let* (cdr bindings))
;    )
;    (eval expr)
;)
(define-macro (let* bindings expr)
    ;(print `expr = expr)
    (if (null? bindings)
        `(let () ,expr)
        `(let (,(car bindings)) (let* ,(cdr bindings) ,expr))
    )
)


;;; Just For Fun Problems


; Helper Functions for you
(define (cadr lst) (car (cdr lst)))
(define (cddr lst) (cdr (cdr lst)))
(define (caddr lst) (car (cdr (cdr lst))))
(define (cdddr lst) (cdr (cdr (cdr lst))))

(define-macro (infix expr)
    ''your code here
)


; only testing if your code could expand to a valid expression 
; resulting in my/and/2 and my/or/2 not hygienic
(define (gen-sym) 'sdaf-123jasf/a123)

; in these two functions you can use gen-sym function.
; assumption:
; 1. scm> (eq? (gen-sym) (gen-sym))
;    #f
; 2. all symbol generate by (gen-sym) will not in the source code before macro expansion
(define-macro (my/and/2 operands)
    'YOUR-CODE-HERE
)

(define-macro (my/or/2 operands)
    'YOUR-CODE-HERE
)
