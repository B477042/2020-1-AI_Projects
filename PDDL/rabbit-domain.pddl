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
(:action see_Turtle_at_beach
    :parameters (?obj ?x ?y)
    :precondition (and
    (rabbit ?x)(turtle ?y)
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))
    (idkRabbit ?y)
    (idkKing ?x)
    (idkPlan ?x)

  (not(runaway ?x))
    (not(giveCure ?x))

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

(:action follow_turtle_And_Meet_the_king
    :parameters (?obj ?x ?y ?z)
    :precondition (and 
    (rabbit ?x)(turtle ?y)(king ?z)
    (atSea ?x)(atSea ?y)(atSea ?z)
    (not(atLand ?x))(not(atLand ?y))(not(atLand ?Z))
    (idkKing ?x)
    (idkPlan ?x)
    (idkRabbit ?z)
    (not(idkRabbit ?y))

  (not(runaway ?x))
    (not(giveCure ?x))

    )
    :effect (and 
    (not (idkKing ?x))
    (not(idkRabbit ?z))
    (not(idkPlan ?x))

    
    )
)

; 토끼가 용왕의 계획을 알게 되고 살려고 거짓말을 한다
;   x 토끼 y 거북이 z 용왕
; 조건
;     1) 셋다 바다에 있다
;     2) 토끼는 용왕을 알고 있다
;     3) 토끼는 용왕의 계획을 알고 있다
;     4) 용왕과 거북이는 토끼를 알고 있다
; 결과
;     1)거북이와 토끼는 다시 육지로 간다
(:action Tell_a_lie_to_king
    :parameters (?obj ?x ?y ?z)
    :precondition (and 
    (rabbit ?x)(turtle ?y)(king ?z)
    (atSea ?x)(atSea ?y)(atSea ?z)
    (not(atLand ?x))(not(atLand ?y))(not(atLand ?Z))
    (not(idkKing ?x))(not(idkPlan ?x))
    (not(idkRabbit ?z))(not(idkRabbit ?y))

      (not(runaway ?x))
    (not(giveCure ?x))
    )
    :effect (and 
    (atLand ?x) (atLand ?y)
    (not(atSea ?x))(not (atSea ?y))
    )
)

; 육지로 올라온 토끼가 도망간다
; 조건
;     1) 둘 다 육지에 있다
;     2) 토끼는 용왕을 알고 계획을 알고 있다
;     3) 거북이는 토끼를 알고 있다
; 결과
;     1) 토끼가 도망간다
(:action Runaway_from_turtle
    :parameters (?obj ?x ?y) 
    :precondition (and
    (rabbit ?x)(turtle ?y)
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))
    (not(idkRabbit?y))
    (not(idkKing ?x))
    (not(idkPlan ?x))
    (not(runaway ?x))
    (not(giveCure ?x))
     )
    :effect (and
    (runaway ?x)
     )
)

; 토끼가 불쌍해서 약을 준다
; 조건
;     1) 둘 다 육지에 있다
;     2) 토끼는 도망갔다
;     3) 토끼는 용왕과 계획을 알고 있다
;     4) 거북이는 토끼를 알고 있다
; 결과
;     1) 토끼가 약을 준다

(:action give_cure_to_turtle
    :parameters (?obj ?x ?y) 
    :precondition (and
    (rabbit ?x)(turtle ?y)
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))
    (not(idkRabbit?y))
    (not(idkKing ?x))
    (not(idkPlan ?x))
    (runaway ?x)
    (not(giveCure ?x))
     )
    :effect (and 
    (giveCure ?x)
    )
)


)
