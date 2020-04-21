#ifndef AACTOR
#define AACTOR

#include <vector>

#include "Entity.h"


/*
	

*/


class AActor:public AEntity
{
public:
	AActor();
	virtual ~AActor();
	virtual void BeginPlay();
	virtual void Update(float DeltaTime);
	virtual void UpdateComponents(float DeltaTime);
	virtual void EndPlay();
	
	//const AComponent*GetCompnent(EComponentType type);

	//string GetName() { return name; }
//	EActorType GetType() { return actorType; }
//	ESide GetSide() { return side; }
	//입력 방향으로 움직인다
	//void MoveTo(ESide side) { this->side = side; }
protected:
	//void resetTimer() { ActionTimer = 0; }
	//void tickTimer(float DeltaTime) { ActionTimer += DeltaTime; }
	////Timer가 제한시간을 넘었는지 체크한다. 만약 넘었다면, true가 반환된다
	//bool isTimerOver() { if (ActionTimer >= LimitTime)return true; return false; }
	//

protected:
	/*vector<AComponent*>Components;
	EComponentType Type;*/
	//float ActionTimer;
	//float LimitTime;
	//string name;
	//EActorType actorType;
	//ESide side;
};



#endif // !AACTOR
