(define (problem Turtle-Prob) (:domain TurtleDomain)
(:objects 
    turtleA kingA rabbitA
)

; 초기상태
;     별주부
;         - 바다에 있습니다
;         - 토끼를 모릅니다
;         - 약을 가지고 있지 않습니다
;     용왕
;         - 바다에 있습니다
;         - 토끼를 모릅니다
;         - 치료받지 못했습니다
;     토끼
;         - 육지에 있습니다
;         - 왕을 모릅니다
(:init

    (turtle turtleA)
    (atSea turtleA)
    (not(atLand turtleA))
    (not(haveCure turtleA))
    (idkRabbit turtleA)

    (king kingA)
    (atSea kingA)
    (not(atLand kingA))
    (idkRabbit kingA)
    (not(isHealed kingA))
    

    (rabbit rabbitA)
    (atLand rabbitA)
    (not(atSea rabbitA))
    (idkKing rabbitA)

    ;todo: put the initial state's facts and numeric values here
)
;별주부가 약을 가지고 돌아와 왕을 치료하면 끝입니다
(:goal (and
   ;todo: put the goal condition here
  (isHealed kingA)
   
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
