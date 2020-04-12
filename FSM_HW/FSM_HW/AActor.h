#ifndef AACTOR
#define AACTOR

#include <vector>

#include "Entity.h"
#include "Component.h"


/*
	이 대화에 나오게될 엑터 클래스
	업데이트를 통해서 작업하게 될 것이다. 

*/
enum EActorType
{
	Actor = 0,
	Police,
	Person,
	Pseudo
};

class AActor:public AEntity
{
public:
	AActor();
	virtual ~AActor();
	virtual void BeginPlay();
	virtual void Update(float DeltaTime);
	virtual void UpdateComponents(float DeltaTime);
	virtual void EndPlay();
	
	const AComponent*GetCompnent(EComponentType type);

	string GetName() { return name; }
	EActorType GetType() { return actorType; }
	
protected:
	void resetTimer() { ActionTimer = 0; }
	void tickTimer(float DeltaTime) { ActionTimer += DeltaTime; }
	//Timer가 제한시간을 넘었는지 체크한다. 만약 넘었다면, true가 반환된다
	bool isTimerOver() { if (ActionTimer >= LimitTime)return true; return false; }
	

protected:
	vector<AComponent*>Components;
	EComponentType Type;
	float ActionTimer;
	float LimitTime;
	string name;
	EActorType actorType;
};



#endif // !AACTOR
