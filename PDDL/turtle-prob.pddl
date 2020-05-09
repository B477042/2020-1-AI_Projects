(define (problem Turtle-Prob) (:domain TurtleDomain)
(:objects 
    turtleA kingA rabbitA
)

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

(:goal (and
   ; (not(idkRabbit turtleA))
    ;(atLand turtleA)
    ;(atSea rabbitA)
   ;(not(idkKing rabbitA))
  ; (not(idkRabbit  kingA))
  (isHealed kingA)
    ;todo: put the goal condition here
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
