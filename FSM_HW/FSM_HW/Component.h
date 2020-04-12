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


	EComponentType GetComponentType() { return ComponentType; }

	//OwnerActor�� ��ȯ�Ѵ�. !DownCasting�ؼ� ����� ��
	const AEntity* GetOwner() { return Owner; }

protected:
	void resetTimer() { ActionTimer = 0.0f; }
	void tickTimer(float DeltaTime) { ActionTimer += DeltaTime; }
	bool bIsTimeLimit() { if (ActionTimer >= 1.0f) return true; return false; }
	
protected:

	EComponentType ComponentType;
	
	AEntity* Owner;
	
	float ActionTimer;
	
};




#endif // !COMPONENT


