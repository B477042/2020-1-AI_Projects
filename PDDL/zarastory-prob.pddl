(define (problem Zara-Prob) (:domain ZaraStory-Domain)
(:objects 
    King1 Zara1 Rabbit1
)

(:init
    ;todo: put the initial state's facts and numeric values here
    (king King1)(zara Zara1)
    (atSea King1)(atSea Zara1)
    (not(atLand King1))(not(atLand Zara1))

    (idkCure King1)(idkCure Zara1)
    (idkRabbit King1)(idkRabbit Zara1)
    (isSick King1)

    (rabbit Rabbit1)
    (atLand Rabbit1)
    (not(atSea Rabbit1))

    (idkKing Rabbit1)
    (idkPlan Rabbit1)
    (not(isRunaway Rabbit1))
    (not(giveCure  Rabbit1))

)

(:goal (and
    ;todo: put the goal condition here
    (not(isSick King1))
    ;(atSea Zara1)
)

)

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
