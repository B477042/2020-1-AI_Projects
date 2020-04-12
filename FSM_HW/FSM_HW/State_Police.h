#ifndef STATEPOLICE
#define STATEPOLICE
#include "StateComponent.h"
#include"Police.h"
class AState_Police :
	public AStateComponent
{
public:
	AState_Police(AEntity* Owner) :AStateComponent(Owner)
	{
		ComponentType = EComponentType::StateComponent;

		state = EState::Police_Sleep;
		n_Eating = 0;
		n_Sleep = 0;
		n_OnWalk = 0;

	}
	~AState_Police();
	virtual void BeginPlay()override;
	virtual void Update(float DeltaTime)override;
	virtual void EndPlay()override;
	//State기반의 행동을 합니다
	void Excute();
	//신고를 접수 받습니다
	void GetReported();
	 APolice* GetOwner();
protected:
	//Dialogue Component에 정보를 보내준다
	virtual void sendMessage();

	int n_Eating;
	int n_Sleep;
	int n_OnWalk;
	

	


};


#endif // !STATEPOLICE


