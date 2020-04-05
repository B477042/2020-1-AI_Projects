#ifndef STATE_COMPONENT
#define STATE_COMPONENT


#include "Component.h"

/*
	상태에 대해 정의하는 컴포넌트.
	3 타입의 actor가 서로 다른 상태를 가지게 될 것이니
	또 상속 시켜서 만들어줘야 될것 같다.


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
