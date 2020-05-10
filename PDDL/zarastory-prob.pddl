(define (problem Zara-Prob) (:domain ZaraStory-Domain)
(:objects 
    King1 Zara1 Rabbit1
)


; 초기 상태

;     자라
;         - 바다에 있습니다
;         - 치료법을 모릅니다
;         - 토끼를 모릅니다
;     용왕
;         - 바다에 있습니다
;         - 토끼를 모릅니다
;         - 치료법을 모릅니다
;         - 아픕니다
;     토끼
;         - 육지에 있습니다
;         - 용왕을 모릅니다
;         - 용왕의 계획을 모릅니다
;         - 도망치지 않았습니다
;         - 약을 주지 않았습니다

(:init
    ;todo: put the initial state's facts and numeric values here
    (king King1)(zara Zara1)(rabbit Rabbit1)
    (atSea King1)(atSea Zara1)(atLand Rabbit1)
    (not(atLand King1))(not(atLand Zara1))(not(atSea Rabbit1))

    (idkCure King1)(idkCure Zara1)
    (idkRabbit King1)(idkRabbit Zara1)
    (isSick King1)

     (idkKing Rabbit1)(idkPlan Rabbit1)
    ; (isRunaway Rabbit1)
  

)
; 왕이 아프지 않으면 이야기가 끝납니다
(:goal (and
    ;todo: put the goal condition here
    (not(isSick King1))
   
)

)

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
