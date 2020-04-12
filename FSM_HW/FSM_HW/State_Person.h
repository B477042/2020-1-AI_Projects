#ifndef STATEPERSON
#define STATEPERSON
#include"StateComponent.h"

class AState_Person :
	public AStateComponent
{
public:
	AState_Person(AEntity* Owner) :AStateComponent(Owner)
	{

	}
	~AState_Person();
	virtual void BeginPlay()override;
	virtual void Update(float DeltaTime)override;
	virtual void EndPlay()override;
protected:
	//Dialogue Component에 정보를 보내준다
	virtual void sendMessage();
private:

};


#endif // !STATEPERSON

