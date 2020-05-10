(define (problem Rabbit-Prob) (:domain Rabbit-Domain)
(:objects 
    Rabbit Turtle King
)

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
