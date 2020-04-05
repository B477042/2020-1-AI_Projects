#ifndef STATE_COMPONENT
#define STATE_COMPONENT


#include "Component.h"

/*
	���¿� ���� �����ϴ� ������Ʈ.
	3 Ÿ���� actor�� ���� �ٸ� ���¸� ������ �� ���̴�
	�� ��� ���Ѽ� �������� �ɰ� ����.


*/
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
protected:

};


#endif // !STATE_COMPONENT
