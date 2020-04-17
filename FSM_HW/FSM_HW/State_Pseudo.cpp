#include "State_Pseudo.h"





AState_Pseudo::~AState_Pseudo()
{
}

void AState_Pseudo::BeginPlay()
{
}

void AState_Pseudo::Update(float DeltaTime)
{
	AStateComponent::Update(DeltaTime);

	//ä�������� ���̴�
	if (state == EState::Pseudo_Captured)return;


	Excute();



	if (bIsTimeLimit())resetTimer();
}

void AState_Pseudo::EndPlay()
{
	
}

void AState_Pseudo::Excute()
{

	auto tempOwner = GetOwner();
	if (ActionTimer >= 1.0f)
	switch (state)
	{
		//�����ϱ�
	case EState::Pseudo_Preach:

		
		
			/*	
				
			*/
		if(n_PreachCount==0)
			cout << tempOwner->GetName() <<"��  ������ �����մϴ�" << endl;

		GetOwner()->SayHello();
			n_PreachCount++;
		

		//5������ �����ϸ� ȭ��ǿ� ����
		if (n_PreachCount >= n_LimitPreach)
		{
			cout << tempOwner->GetName() << "�� ȭ��ǿ� ���ϴ�" << endl;
			state = EState::Pseudo_Toilet;
			
		}
		
		break;
		//ȭ��ǰ���
	case EState::Pseudo_Toilet:
		n_PreachCount = 0;
		if (ActionTimer >= 1.0f)
			n_ToiletTime++;

	

		//3������ �����ٸ�
		if (n_ToiletTime >= 3)
		{
			state = EState::Pseudo_Preach;
			cout << tempOwner->GetName() << "�� ȭ��ǿ��� ���� �ٽ� �����մϴ�" << endl;
			n_ToiletTime = 0;
			
		}
			
		break;
		
	}

	
}

void AState_Pseudo::BeingCaputred()
{
	state = EState::Pseudo_Captured;



	//tempOwner->
}


APseudo * AState_Pseudo::GetOwner()
{
	auto tempOwner = (APseudo*)(Owner);
	if (tempOwner == nullptr) { cout << "!!!!!!!Type casting Error" << endl; return nullptr; }
	else return tempOwner;
}
