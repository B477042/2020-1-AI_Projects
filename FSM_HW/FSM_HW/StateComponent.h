#ifndef STATE_COMPONENT
#define STATE_COMPONENT


#include "Component.h"

/*
	���¿� ���� �����ϴ� ������Ʈ.
	3 Ÿ���� actor�� ���� �ٸ� ���¸� ������ �� ���̴�
	�� ��� ���Ѽ� �������� �ɰ� ����.


*/

//��� ���µ�
enum EState
{
	None=0,
	Pseudo_Preach,Pseudo_Toilet,Pseudo_Captured,
	Person_Idle, Person_Runaway,Person_Report,
	Police_Eating,Police_Sleep,Police_OnPatrol,Police_Capture
};


class AStateComponent :
	public AComponent
{
public:
	AStateComponent(AEntity*Owner) :AComponent(Owner)
	{
		ComponentType = EComponentType::StateComponent;
		
	}

	~AStateComponent();
	virtual void BeginPlay()override;
	virtual void Update(float DeltaTime)override;
	virtual void EndPlay()override;
	EState GetState() { return state; }
protected:
	//Dialogue Component�� ������ �����ش�
	virtual void sendMessage();


protected:
	EState state;
};


#endif // !STATE_COMPONENT
