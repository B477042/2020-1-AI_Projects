#ifndef STATEPERSON
#define STATEPERSON
#include"StateComponent.h"
#include"Person.h"
class AState_Person :
	public AStateComponent
{
public:
	AState_Person(AEntity* Owner) :AStateComponent(Owner)
	{
		ComponentType = EComponentType::StateComponent;
		state = EState::Person_Idle;
		n_IdleTime = 0;
	}
	~AState_Person();
	virtual void BeginPlay()override;
	virtual void Update(float DeltaTime)override;
	virtual void EndPlay()override;
	//사이비와 접촉하게 되면 호출됩니다
	void ExposedToPseudo();
protected:

	virtual void sendMessage();
	void excute();
	APerson*GetOwner();
private:
	int n_IdleTime;
	
};


#endif // !STATEPERSON

