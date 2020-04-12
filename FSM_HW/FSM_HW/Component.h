#ifndef COMPONENT
#define	COMPONENT
#include"Entity.h"
#include<map>

//CompnentType�� ������
enum EComponentType
{
	//�⺻��
	Component,
	StateComponent,
	DialogueComponent
};
//Component���� �켱����
enum EPriority
{
	Comopnent =0,
	StateComponent=1,

	DialogueComponent=9
	
};
//�������� 
static map<EComponentType, string> FComponentType = { {EComponentType::Component, "Component"},{EComponentType::DialogueComponent, "DialogueComponent"},{EComponentType::StateComponent, "StateComponent"} };


/*
	Actor�� �ൿ ��ų ������Ʈ��

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
	//���� ������ ���۵Ǳ� ���� ȣ��� ���̴�
	virtual void BeginPlay();
	//���� ���� �ӿ��� ȣ��
	virtual void Update(float DeltaTime);
	//������ ���� �� ó��
	virtual void EndPlay();
	int GetPriority();

	string GetComponentName() { return FComponentType[ComponentType]; }

	//OwnerActor�� ��ȯ�Ѵ�. !DownCasting�ؼ� ����� ��
	const AEntity* GetOwner() { return Owner; }

protected:
	void resetTimer() { ActionTimer = 0.0f; }
	void tickTimer(float DeltaTime) { ActionTimer += DeltaTime; }
protected:

	EComponentType ComponentType;
	EPriority Priority;
	AEntity* Owner;
	
	float ActionTimer;
	
};




#endif // !COMPONENT


