;Header and description

(define (domain TurtleDomain)

;remove requirements that are not needed
(:requirements :strips :equality)

; un-comment following line if constants are needed
;(:constants )

(:predicates ;todo: define predicates here
    (at ?x ?loc);x가 loc에있다
    (alive ?x);x가 살아있다면 true
    (turtle ?x);x는 거북이인가
    (rabbit ?x);x는 토끼인가
    (king ?x) ;x는 용왕인가
    ()
)

(:action RideTo
    :parameters (obj x,y)
    :precondition (and )
    :effect (and )
)




)