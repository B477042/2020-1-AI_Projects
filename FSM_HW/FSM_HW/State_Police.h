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
	
	//�Ű� ���� �޽��ϴ�
	void GetReported();
	 APolice* GetOwner();
protected:
	//State����� �ൿ�� �մϴ�
	void Excute();



	//���¸� ���� ��Ű�� ī���͵�
	int n_Eating;
	int n_Sleep;
	int n_OnWalk;
	

	


};


#endif // !STATEPOLICE


