;Header and description

    ; 스토리
    ; 별주부 시점에서 진행되고
    ; 적어도 하나의 성공적인 플랜을 찾는다
    ; 별주부 시점 : 목표 : 용왕의 치료

    ; 1. 왕의 명령을 받고 토끼를 찾아 육지로 간다
    ; 2. 육지에서 토끼를 찾는다
    ; 3. 토끼를 대리고 용궁으로 간다
    ; 4. 토끼가 용왕에게 다시 올라가야된다고 하니 육지로 간다
    ; 5. 토끼가 도망간다
    ; 6. 토끼가 불쌍해서 똥을 준다
    ; 7. 똥을 가지고 돌아가면 용왕이 산다

(define (domain TurtleDomain)

;remove requirements that are not needed
(:requirements :strips :equality :negative-preconditions)

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
    (isHealed ?x);x가 치료를 받았는가
    (haveCure ?x);x가 약을 가지고 있는가
)


; x는 용왕 y는 별주부
; 조건  
;       1)둘 다 바다에 있어야 된다.
;       2)토끼를 만난적이 없어야 된다
; 결과 : 별주부는 육지로 간다
(:action order_find
    :parameters (?x ?y)
    :precondition (and 
    (king ?x)(turtle ?y)
  
    (atSea ?x)(atSea ?y)
    (idkRabbit ?x)(idkRabbit ?y)
     )
    :effect (and 
    (not(atsea ?y))
    (atLand ?y)
    )
)
; x는 별주부 y는 토끼
; 조건
;     
;     1)둘 다 육지에 있다
;     2)별주부는 토끼를 모른다
;     3)토끼는 용왕을 모른다
; 결과
;     1)둘 다 바다로 간다
;     2)별주부는 토끼를 알게 된다

(:action find_Rabbit_and_goto_sea
    :parameters (?x ?y)
    :precondition (and
    (turtle ?x)(rabbit ?y)
   
    (atLand ?x)(atLand ?y)
    (idkRabbit ?x)(idkKing ?y)
    
     )
    :effect (and 
    
    (atSea ?x)(atSea ?y)
    (not(atLand ?X))(not(atLand ?y))
    (not(idkRabbit ?x))

    )
)

; X 별주부 Y 토끼 Z 용왕
; 조건 
;    
;     1) 셋 다 용궁에 있다
;     2) 별주부는 토끼를 알고 있지만 용왕은 모른다
;     3) 토끼는 용왕을 모른다
; 결과
;     1) 용왕은 토끼를 알게 된다
;     2) 토끼는 용왕을 알게된다

(:action meet_king_and_rabbit
    :parameters (?obj ?x ?y ?z)
    :precondition (and
    (turtle ?x) (rabbit ?y)(king ?z)
    
    (atSea ?x)(atSea ?y)(atSea ?z)
    (not(atLand ?x))(not(atLand ?y))(not(atLand ?z))
    (not(idkRabbit ?x))(idkRabbit ?z)(idkKing ?y)

    )
    :effect (and 
    (not(idkRabbit ?z))
    (not(idkKing ?y))
    ) 
)


; 조건
;     
;     1)셋 다 용궁에 있다
;     2) 별주부와 용왕은 토끼를 알고 있다
;     3) 토끼는 용왕을 알고 있다
; 결과
;     1)별주부와 토끼는 육지로 간다    

(:action Rabbit_tell_secret
     :parameters (?obj ?x ?y ?z)
     
    :precondition (and
    (turtle ?x) (rabbit ?y)(king ?z)
    
    (atSea ?x)(atSea ?y)(atSea ?z)
    (not(atLand ?x))(not(atLand ?y))(not(atLand ?z))
    (not(idkRabbit ?x))(not(idkRabbit ?z))
    (not(idkKing ?y))
    )

    :effect (and
    (not (atSea ?x))(not (atSea ?y))
    (atLand ?x)(atLand ?y)
    
     )
)

; 육지에 도착하자 달아난다
;     X는 별주주 Y는 토끼
; 조건
;     1)둘 다 육지에 있다
;     2)토끼는 용왕을 알고 있다. 별주부는 토끼를 알고 있다
;     3)별주부는 약을 가지고 있지 않다
; 결과
;     1) 별주부는 약을 얻는다

(:action Runaway
    :parameters (?obj ?x ?y)
    :precondition (and 
    (turtle ?x)(rabbit ?y)
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))
    (not(idkRabbit ?x))
    (not(idkKing ?y))
    (not(haveCure ?x))
    )
    :effect (and 
    (haveCure ?x)

    )
)

(:action take_Cure_back_to_king
    :parameters (?obj ?x )
    :precondition (and 
    (turtle ?x)
    (atLand ?x)
    (not(atSea ?x))
    (haveCure ?x)
    (not(idkRabbit ?x))
    )
    :effect (and
    (atSea ?x)
    (not (atLand ?x))
    

     )
)

(:action healed
    :parameters (?obj ?x ?y)
    :precondition (and 
    (turtle ?x)(king ?y)
    (atSea ?x)(atSea ?y)
    (not(atLand ?x))(not(atLand ?y))

    (not(idkRabbit ?x))(not(idkRabbit ?y))
    
    (haveCure ?x)

    )
    :effect (and 
        (isHealed ?y)
    )
)





)