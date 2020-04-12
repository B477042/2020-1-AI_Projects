#ifndef STATEPSEUDO
#define STATEPSEUDO
#include"StateComponent.h"
#include"Pseudo.h"



class AState_Pseudo :
	public AStateComponent
{
public:
	AState_Pseudo(AEntity* Owner) :AStateComponent(Owner)
	{
		state = EState::Pseudo_Preach;
		n_PreachCount = 0;
		n_ToiletTime = 0;
		//bFindPerson = false;
		n_LimitPreach = 5;
	
	}
	~AState_Pseudo();
	virtual void BeginPlay()override;
	virtual void Update(float DeltaTime)override;
	virtual void EndPlay()override;


	
	void BeingCaputred();
protected:
	//상태에 맞는 행동하기
	void Excute();
	//Dialogue Component에 정보를 보내준다
	virtual void sendMessage();
	APseudo* GetOwner();
	
protected:

	//전도한 횟수
	int n_PreachCount;
	//화장실에 들어가있는 시간
	int n_ToiletTime;
	int n_LimitPreach;
	
};

#endif // !STATEPSEUDO


