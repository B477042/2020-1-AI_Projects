;Header and description

; 토끼 시점 스토리
; 1. 육지에 온 거북이를 발견
; 2. 거북이를 따라감
; 3. 용왕의 일에 대해 알게됨
; 4. 거짓말을 함
; 5. 육지로 올라와서
; 7. 도망감
; 8. 불쌍해서 약을 줌

(define (domain Rabbit-Domain)

;remove requirements that are not needed
(:requirements :strips :equality :negative-preconditions)

; un-comment following line if constants are needed
;(:constants )
; un-comment following line if constants are needed
;(:constants )

(:predicates ;todo: define predicates here
    (atSea ?x);x가 바다에 있는가
    (atLand ?x);x가 육지에 있는가
    (turtle ?x);x는 거북이인가
    (rabbit ?x);x는 토끼인가
    (king ?x) ;x는 용왕인가
    (idkRabbit ?x);x는 토끼를 알지 못한다
    (idkKing ?x);x는 왕을 알지 못한다
    (idkPlan ?x);x는 용왕의 계획을 알지 못한다
    (runaway ?x);x가 도망갔는가
    (giveCure ?x);x가 약을 줬는가
)



;define actions here
;토끼가 거북이를 발견한다
;조건
; 1) 둘다 육지에 있다
; 2) 거북이는 토끼를 알지 못한다
; 3) 토끼는 왕을 알지 못한다
; 결과
; 1) 둘 다 바다로 간다
; 2) 거북이는 토끼를 알게 된다
(:action see_Turtle
    :parameters (?obj ?x ?y)
    :precondition (and
    (rabbit ?x)(turtle ?y)
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))
    (idkRabbit ?y)
    (idkKing ?x)
    (idkPlan ?x)
     )
    :effect (and
    (atSea ?x)(atSea ?y)
    (not (atLand ?x))(not (atLand ?y))
    (not(idkRabbit ?y))

     )
)

; 거북이를 따라 바다로 가서 용왕을 보게 되다
; x 토끼 y 거북이 z 용왕
; 조건
;     1)셋다 바다에 있다
;     2)용왕은 토끼를 모른다
;     3)토끼는 용왕을 모른다
;     4)거북이는 토끼를 알고 있다
; 결과
;     1)토끼는 용왕을 알게 된다
;     2)토끼는 계획을 알게 된다
;     3)용왕은 토끼를 알게 된다

(:action followTurtleAndSeeKing
    :parameters (?obj ?x?y?z)
    :precondition (and 
    (rabbit ?x)(turtle ?y)(king ?z)
    (atSea ?x)(atSea ?y)(atSea ?z)
    (not(atLand ?x))(not(atLand ?y))(not(atLand ?Z))
    (idkKing ?x)
    (idkRabbit ?z)
    (not(idkRabbit ?y))

    )
    :effect (and 
    (not (idkKing ?x))
    (not(idkRabbit ?z))
    (not(idkPlan ?x))

    
    )
)


(:action Tell_a_line_
    :parameters ()
    :precondition (and )
    :effect (and )
)



)
