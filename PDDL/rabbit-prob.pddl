(define (problem Rabbit-Prob) (:domain Rabbit-Domain)
(:objects 
    Rabbit Turtle King
)



; 초기 상태
;     토끼 
;         - 육지에 있습니다
;         - 도망가지 않았습니다
;         - 약을 주지 않았습니다
;         - 왕의 계획을 모릅니다
;         - 왕을 모릅니다
;     별주부
;         - 바다에 있습니다
;         - 토끼를 모릅니다
;     용왕
;         - 바다에 있습니다
;         - 토끼를 모릅니다


(:init
    (rabbit Rabbit)
    (not(atSea Rabbit))
    (atLand Rabbit)
    (not(runaway Rabbit))
    (not(giveCure Rabbit))
    (idkPlan Rabbit)
    (idkKing Rabbit)

    (turtle Turtle)
    (atLand Turtle)
    (not(atSea Turtle))
    (idkRabbit Turtle)

    (king King)
    (atSea King)
    (not(atLand King))
    (idkRabbit King)

    ;todo: put the initial state's facts and numeric values here
)
; 약을 거북이에게 주면 이야기는 끝납니다
(:goal (and
    ;todo: put the goal condition here
  ;  (not(idkPlan Rabbit) )
  ;(atSea Turtle)
 ; (not(idkRabbit King))
 (giveCure Rabbit)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
