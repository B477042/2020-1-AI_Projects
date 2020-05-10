;Header and description
; 1. 어느 날 바다 속 용왕이 큰 병에 걸린다.
; 2. 병을 간호하는 의사들은 용왕의 병이 낫기 위해서는 육지에 사는 토끼의 간이 필요하다고 말한다.
; 3. 용왕은 자라 별주부에게 토끼 간을 구해오라고 명령한다.
; 4. 충성심 강한 별주부는 즉시 토끼를 찾으러 육지로 올라가고, 육지에서 토끼 한 마리를 발견한다.
; 5. 별주부는 토끼에게 바다 구경을 시켜준다고 꾀어서 토끼를 바다 속 용궁으로 데려 간다.
; 6. 용궁에 온 토끼는 별주부를 따라 바다 구경을 하지만 실제로는 자기 몸속에 있는 간이 필요해서 데리고 온 것이며, 자신의 목숨이 위태롭다는 것을 깨닫는다.
; 7. 토끼는 당황했지만 곧바로 꾀를 내어 용왕에게 간을 육지에 놓고 왔다고 태연하게 거짓말을 하고는 자라 별주부를 타고 육지로 다시 올라온다.
; 8. 육지에 온 토끼는 별주부에게 세상 어느 동물이 간을 놓고 다니겠느냐고 별주부를 놀린다.
; 9. 하지만, 크게 상심한 별주부를 본 토끼는 마음이 약해져서 대신 다른 약을 주겠다고 말하며 까맣고 작은 똥을 싸서는 풀잎에 담아 주고 숲으로 사라진다.
; 10. 별주부는 풀잎에 담긴 토끼 똥을 갖고 용궁으로 돌아가고, 용왕은 이를 먹고 병이 나았다고 한다.




(define (domain ZaraStory-Domain)

;remove requirements that are not needed
(:requirements :strips :equality :negative-preconditions)


; un-comment following line if constants are needed
;(:constants )

(:predicates ;todo: define predicates here
    (zara ?x);x는 자라인가
    (rabbit ?x);x는 토끼인가
    (king ?x);x는 용왕인가

    (atSea ?x);x는 바다에 있는가
    (atLand ?x);x는 육지에 있는가

    (idkRabbit ?x);x는 토끼를 모른다
    (idkKing ?x);x는 왕을 모른다
    (idkPlan ?x);x는 왕의 계획을 모른다
    (idkCure ?x);x는 병에 대한 처방을 모른다

    (isSick ?x);x는 아픈가
    (isRunaway ?x);x가 도망갔는가
    (giveCure ?x);x는 약을 준 적이 있는가
    

)



;define actions here

; 용왕이 병에 걸렸습니다
; 조건
;     1) 자라와 왕은 바다에 있다
;     2) 자라와 왕은 치료법을 모른다
;     3) 자라와 왕은 토끼를 알지 못한다
;     4) 왕은 아프다
; 결과
;     1)왕과 자라는 치료법을 알게 된다
    
(:action King_got_a_sick
    :parameters (?obj ?x ?y)
    :precondition (and 
    (king ?x)(zara ?y)
    (atSea ?x)(atSea ?y)
    (not(atLand ?x))(not(atLand ?y))
    (idkCure ?x)(idkCure ?y)
    (idkRabbit ?x)(idkRabbit ?y)
    (isSick ?x)

    )
    :effect (and 
    (not(idkCure ?x))(not (idkCure ?y))


    )
)

; 의사가 토끼의 간이 약이라고 알려줍니다
; 조건
;     1) 왕과 자라는 육지에 있다
;     2) 왕과 자라는 토끼를 모른다
;     3) 왕과 자라는 치료법을 알고 있습니다
;     4) 왕은 아프다
; 결과
;     1) 자라는 육지로 간다

(:action Doctor_say_liver_of_rabbit_is_cure
    :parameters (?obj ?x ?y)
    :precondition (and 
    (king ?x)(zara ?y)
    (atSea ?x)(atSea ?y)
    (not(atLand ?x))(not(atLand ?y))

    (not(idkCure ?x))(not(idkCure ?y))

    (idkRabbit ?x)(idkRabbit ?y)

    (isSick ?x)

    )
    :effect (and 
    (atLand ?y)
    (not(atSea ?y))
    )
)

; 왕은 자라에게 토끼를 찾아오라고 합니다
; 조건
;     1) 왕은 바다에 있습니다
;     2) 왕은 토끼를 모릅니다
;     3) 왕은 아픕니다
;     4) 왕은 치료법을 알고 있습니다
;     5) 자라는 육지에 있습니다
;     6) 자라는 토끼를 모릅니다
;     7) 자라는 치료법을 알고 있습니다
; 결과
;     1) 자라는 토끼를 알게 됩니다

(:action king_order_to_zara_to_find_rabbit
     :parameters (?obj ?x ?y)
    :precondition (and 
    (king ?x)(zara ?y)
    (atSea ?x)(not(atSea ?y))
    (not(atLand ?x))(atLand ?y)

    (not(idkCure ?x))(not(idkCure ?y))

    (idkRabbit ?x)(idkRabbit ?y)

    (isSick ?x)

    )
    :effect (and 
    (not(idkRabbit ?y))
    )
)

; 자라는 육지에서 토끼 한마리를 찾게 됩니다
; 조건
;     1) 자라는 육지에 있습니다
;     2) 자라는 토끼를 압니다
;     3) 자라는 치료법을 압니다
;     4) 토끼는 왕을 모릅니다
;     5) 토끼는 용와의 계획을 모릅니다
;     6) 토끼는 육지에 있습니다
;     7) 토끼는 도망가지 않았습니다
;     8) 토끼는 선물을 주지 않았습니다
; 결과
;     1) 토끼와 자라는 바다로 갑니다

(:action zara_find_rabbit
    :parameters (?obj ?x ?y)
    :precondition (and 
    (zara ?x)(rabbit ?y)
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))

    (not(idkRabbit ?x))
    (not(idkCure ?x))

    (idkKing ?y)
    (idkPlan ?y)
    (not(isRunaway ?y))
    (not(giveCure ?y))

    )
    :effect (and 
    (atSea ?x)(atSea ?y)
    (not(atland ?x))(not (atLand ?y))

    )
)

; 자라가 토끼를 설득해서 바다로 대려갑니다
; 조건
;     1) 자라와 토끼는 바다에 있습니다
;     2) 자라는 토끼를 압니다
;     3) 자라는 치료법을 압니다
;     4) 토끼는 왕을 모릅니다
;     5) 토끼는 용왕의 계획을 모릅니다
;     6) 토끼는 도망가지 않았습니다
;     7) 토끼는 선물을 주지 않았습니다
; 결과
;     1) 토끼는 용왕을 알게 됩니다

(:action Zara_persuaded_the_rabbit_to_come_to_the_sea
    :parameters (?obj ?x ?y)
    :precondition (and
    (zara ?x)(rabbit ?y)
    (atSea ?x)(atSea ?y)
    (not(atland ?x))(not (atLand ?y))

    (not(idkRabbit ?x))
    (not(idkCure ?x))

    (idkKing ?y)
    (idkPlan ?y)
    (not(isRunaway ?y))
    (not(giveCure ?y))


     )
    :effect (and 
    (not(idkKing ?y))
    )
)

; 왕이 토끼의 간을 뺄려고 합니다
; 조건
;     1)토끼 자라 왕은 바다에 있습니다
;     2) 토끼는 왕을 알고 있습니다
;     3) 토끼는 왕의 계획을 모릅니다
;     4) 토끼는 도망가지 않았습니다
;     5) 토끼는 약을 주지 않았습니다
;     6) 자라는 토끼를 알고 있습니다
;     7) 왕은 토끼를 모릅니다
;     8) 왕과 자라는 치료법을 알고있습니다
      ;9) 왕은 아픕니다
; 결과
;     1) 토끼는 왕의 계획을 알게 됩니다
;     2) 왕은 토끼를 알게 됩니다
(:action King_trying_to_take_liver_of_rabbit
    :parameters (?obj ?x ?y ?z)
    :precondition (and
    (zara ?x)(rabbit ?y)(king ?z)
    (atSea ?x)(atSea ?y)(atSea ?z)
    (not(atland ?x))(not (atLand ?y))(not(atSea ?z))

   

    (not(idkKing ?y))
    (idkPlan ?y)
    (not(isRunaway ?y))
    (not(giveCure ?y))

    (idkRabbit ?z)
    
    (not(idkRabbit ?x))
    (not(idkCure ?x))(not(idkCure ?z))
    (isSick ?z)
     )
    :effect (and 
    (not(idkRabbit ?z))
    (not(idkPlan ?y))
    )
)

; 토끼가 거짓말을 하고 간을 가지러 다시 올라갑니다
; 조건
;     1) 셋 다 바다에 있습니다
;     2) 토끼는 왕을 알고 있습니다
;     3) 토끼는 왕의 계획을 알고 있습니다
;     4) 토끼는 도망가지 않았습니다
;     5) 토끼는 약을 주지 않았습니다
;     6) 자라와 왕은 토끼를 알고 있습니다
;     7) 자라와 왕은 치료법을 알고 있습니다
;     8) 왕은 아픕니다
; 결과
;     1) 자라와 토끼는 육지로 갑니다
(:action Rabbit_tell_a_lie_to_king
  :parameters (?obj ?x ?y ?z)
    :precondition (and
    (zara ?x)(rabbit ?y)(king ?z)
    (atSea ?x)(atSea ?y)(atSea ?z)
    (not(atland ?x))(not (atLand ?y))(not(atSea ?z))

    

    (not(idkKing ?y))
    (not(idkPlan ?y))
    (not(isRunaway ?y))
    (not(giveCure ?y))

    (not(idkRabbit ?x))(not(idkRabbit ?z))
    (not(idkCure ?x))(not(idkCure ?z))
    (isSick ?z)
     )
    :effect (and
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))
     )
)

; 육지로 올라온 토끼는 도망갑니다
; 조건
;     1) 둘 다 육지에 있습니다
;     2) 자라는 토끼를 알고 있습니다
;     3) 자라는 약을 알고 있습니다
;     4) 토끼는 도망가지 않았습니다
;     5) 토끼는 용왕을 알고 있습니다
;     6) 토끼는 계획을 알고있습니다
;     7) 토끼는 약을 주지 않았습니다.
; 결과
;     1) 토끼는 도망갑니다
    (:action Rabbit_runaway_from_zara
        :parameters (?obj ?x ?y)
    :precondition (and 
    (zara ?x)(rabbit ?y)
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))

    (not(idkRabbit ?x))
    (not(idkCure ?x))

  
    (not(idkKing ?y))
    (not(idkPlan ?y))
    (not(isRunaway ?y))
    (not(giveCure ?y))

    )
        :effect (and 
        (isRunaway ?y)
        )
    )
    
;토끼가 거북이에게 약을 줍니다
;조건
 ;    1) 둘 다 육지에 있습니다
;     2) 자라는 토끼를 알고 있습니다
;     3) 자라는 약을 알고 있습니다
;     4) 토끼는 도망갔습니다
;     5) 토끼는 용왕을 알고 있습니다
;     6) 토끼는 계획을 알고있습니다
;     7) 토끼는 약을 주지 않았습니다.
; 결과
;     1) 토끼가 약을 줬습니다
;       2)자라는 바다로 돌아갑니다

(:action Rabbit_give_cure_to_zara
    :parameters (?obj ?x ?y)
    :precondition (and 
    (zara ?x)(rabbit ?y)
    (atLand ?x)(atLand ?y)
    (not(atSea ?x))(not(atSea ?y))

    (not(idkRabbit ?x))
    (not(idkCure ?x))

  
    (not(idkKing ?y))
    (not(idkPlan ?y))
    (isRunaway ?y)
    (not(giveCure ?y))

    )
    :effect (and 
    (giveCure ?y)
    (atSea ?x)
    (not(atLand ?x))
    )
)

;왕은 약을 먹고 병이 나았습니다
(:action king_recover
    :parameters (?obj ?x ?y ?z)
    :precondition (and 
    
    (zara ?x)(rabbit ?y)(king ?z)
    (atSea ?x)(atLand ?y)(atSea ?z)
    (not(atland ?x))(not(atSea ?y))(not(atSea ?z))

    (not(idkRabbit ?x))(not(idkRabbit ?z))
    (not(idkCure ?x))(not(idkCure ?z))

    
    (not(idkKing ?y))
    (not(idkPlan ?y))
    (isRunaway ?y)
    (giveCure ?y)

    
    (isSick ?z)
    )

    :effect (and
    (not(isSick ?z))
    )
)



)