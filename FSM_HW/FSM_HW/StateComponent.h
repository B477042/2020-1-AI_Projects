#ifndef STATE_COMPONENT
#define STATE_COMPONENT


#include "Component.h"

/*
	���¿� ���� �����ϴ� ������Ʈ.
	3 Ÿ���� actor�� ���� �ٸ� ���¸� ������ �� ���̴�
	�� ��� ���Ѽ� �������� �ɰ� ����.


*/
class EState
{
public:
	
};


class AStateComponent :
	public AComponent
{
public:
	AStateComponent(AEntity*Owner) :AComponent(Owner)
	{
		ComponentType = EComponentType::StateComponent;
		Priority = EPriority::StateComponent;
	}

	~AStateComponent();
	virtual void BeginPlay()override;
	virtual void Update(float DeltaTime)override;
	virtual void EndPlay()override;
	virtual string GetState() = 0;
protected:

};


#endif // !STATE_COMPONENT
