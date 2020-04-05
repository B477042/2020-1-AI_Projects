#ifndef COMPONENT
#define	COMPONENT
#include"Entity.h"
#include<map>

//CompnentType의 열거형
enum EComponentType
{
	//기본형
	Component,
	StateComponent,
	DialogueComponent
};
//전역변수 
static map<EComponentType, string> FComponentType = { {EComponentType::Component, "Component"},{EComponentType::DialogueComponent, "DialogueComponent"},{EComponentType::StateComponent, "StateComponent"} };


/*
	Actor를 행동 시킬 컴포넌트형

*/
class AComponent :public AEntity
{
public:
	AComponent(AEntity* Owner) :Owner(Owner)
	{
		ComponentType = EComponentType::Component;
		resetTimer();
	
	}

	~AComponent();
	//메인 루프가 시작되기 전에 호출될 것이다
	virtual void BeginPlay();
	//메인 루프 속에서 호출
	virtual void Update(float DeltaTime);
	//루프가 끝난 후 처리
	virtual void EndPlay();


	string GetComponentName() { return FComponentType[ComponentType]; }

	//OwnerActor를 반환한다. !DownCasting해서 사용할 것
	const AEntity* GetOwner() { return Owner; }

protected:
	void resetTimer() { ActionTimer = 0.0f; }
	void tickTimer(float DeltaTime) { ActionTimer += DeltaTime; }
protected:

	EComponentType ComponentType;
	AEntity* Owner;

	float ActionTimer;
};




#endif // !COMPONENT


