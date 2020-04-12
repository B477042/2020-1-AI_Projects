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
	//���¿� �´� �ൿ�ϱ�
	void Excute();
	//Dialogue Component�� ������ �����ش�
	virtual void sendMessage();
	APseudo* GetOwner();
	
protected:

	//������ Ƚ��
	int n_PreachCount;
	//ȭ��ǿ� ���ִ� �ð�
	int n_ToiletTime;
	int n_LimitPreach;
	
};

#endif // !STATEPSEUDO


