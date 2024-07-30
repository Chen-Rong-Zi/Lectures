;;; HW08: Scheme

;;; Required Problems

(define (square x) (* x x))

(define (pow base exp)
    (if (= exp 0)
        (define result 1)
        (if (= (remainder exp 2) 1)
            (define result
                (* base (pow base (- exp 1)))
            )
            (define result
                (square(pow base (/ exp 2)))
            )
        )
    )
    result
)


(define (filter-lst fn lst)
    (cond
        ((null? lst) nil)
        ((fn (car lst))
            (append (list (car lst))
            (filter-lst fn (cdr lst)))
        )
        (else (filter-lst fn (cdr lst)))
    )
)


(define (no-repeats s)
    (define (not_n n)
        (define (not_n_helper x)
            (if (= n x) #f #t)
        )
        not_n_helper
    )
    (define (helper so_far lst)
        (if (null? lst)
            so_far
            (helper
                (append so_far (list (car lst)))
                (filter (not_n (car lst)) lst)
            )
        )
    )
    (helper nil s)
)

; (define (no-repeats s)
;     (define (in_lst n lst)
;         (define (in_lst_helper n lst result)
;             (if (null? lst)
;                 result
;                 (in_lst_helper n (cdr lst) (or result (= n (car lst))))
;             )
;         )
;         (in_lst_helper n lst #f)
;     )
; 
;     (define (helper so_far lst)
;         (if (null? lst)
;             so_far
;             (if (in_lst (car lst) so_far)
;                 (helper so_far (cdr lst))
;                 (helper (append so_far (list (car lst))) (cdr lst))
;             )
;         )
;     )
;     (helper nil s)
; )


; (define string (a b c d d d e e e f))
; (substitute string d e)
; (a b c e e e e e e f)
(define (substitute s old new)
    (define (sub_helper result remain)
        (if (null? remain)
            result
            (if (list? (car remain))
                (sub_helper (append result (list(substitute (car remain) old new))) (cdr remain))
                (if (eq? old (car remain))
                    (sub_helper (append result (list new)) (cdr remain))
                    (sub_helper (append result (list(car remain))) (cdr remain))
                )
            )
        )
    )
    (sub_helper nil s)
)


(define (sub-all s olds news)
    (define (sub-helper result olds news)
        (if (null? news)
            result
            (sub-helper (substitute result (car olds) (car news)) (cdr olds) (cdr news))
        )
    )
    (sub-helper s olds news)
)


(define (tree label branches)
    (cons label branches)
)

(define (label t)
    (car t)
)

(define (branches t)
    (cdr t)
)

(define (is-leaf t)
    (if (null? (branches t))
        #t
        #f
    )
)

; A tree for test

(define t1
  (tree 1
    (list
      (tree 2
        (list
          (tree 5 nil)
            (tree 6 (list
              (tree 8 nil)
            )
          )
        )
      )
      (tree 3 nil)
      (tree 4
        (list
          (tree 7 nil)
        )
      )
    )
  )
)

(define (label-sum t)
    (define (branch_sum bs)
        (define (branch_sum_helper bs result)
            (if (null? bs)
                result
                (branch_sum_helper (cdr bs) (+ result (label-sum (car bs)) ))
            )
        )
        (branch_sum_helper bs 0)
    )

    (if (is-leaf t)
        (label t)
        (+ (label t) (branch_sum (branches t)))
    )
)

;def label_sum(tree):
;    if is_leaf(tree):
;        return label(tree)
;    result = 0
;    for b in branches(tree):
;        result + label_sum(b)
;    return result + label(tree)


;;; Just for fun Problems

(define (cadr s) (car (cdr s)))
(define (caddr s) (car (cdr (cdr s))))

; derive returns the derivative of EXPR with respect to VAR
(define (derive expr var)
    (cond ((number? expr) 0)
        ((variable? expr) (if (same-variable? expr var) 1 0))
        ((sum? expr) (derive-sum expr var))
        ((product? expr) (derive-product expr var))
        ((exp? expr) (derive-exp expr var))
        (else 'Error)))

; Variables are represented as symbols
(define (variable? x) (symbol? x))
(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))

; Numbers are compared with =
(define (=number? expr num)
  (and (number? expr) (= expr num)))

; Sums are represented as lists that start with +.
(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))
(define (sum? x)
  (and (list? x) (eq? (car x) '+)))
(define (first-operand s) (cadr s))
(define (second-operand s) (caddr s))

; Products are represented as lists that start with *.
(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2)) (* m1 m2))
        (else (list '* m1 m2))))
(define (product? x)
  (and (list? x) (eq? (car x) '*)))
; You can access the operands from the expressions with
; first-operand and second-operand
(define (first-operand p) (cadr p))
(define (second-operand p) (caddr p))

(define (derive-sum expr var)
  'YOUR-CODE-HERE
)

(define (derive-product expr var)
  'YOUR-CODE-HERE
)

; Exponentiations are represented as lists that start with ^.
(define (make-exp base exponent)
  'YOUR-CODE-HERE
)

(define (exp? exp)
  'YOUR-CODE-HERE
)

(define x^2 (make-exp 'x 2))
(define x^3 (make-exp 'x 3))

(define (derive-exp exp var)
  'YOUR-CODE-HERE
)
