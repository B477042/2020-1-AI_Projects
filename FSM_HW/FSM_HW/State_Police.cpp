#include "State_Police.h"
#include"EventManager.h"
#include"Pseudo.h"



AState_Police::~AState_Police()
{
}

void AState_Police::BeginPlay()
{
}

void AState_Police::Update(float DeltaTime)
{
	AStateComponent::Update(DeltaTime);
	Excute();


	if (bIsTimeLimit())resetTimer();
}

void AState_Police::EndPlay()
{
	
}

void AState_Police::Excute()
{
	auto tempOwner = GetOwner();
	if (ActionTimer >= 1.0f)
	switch (state)
	{
		//��Ա�
	case Police_Eating:
		if(n_Eating==0)
		cout << tempOwner->GetName() << "�� ���� �԰� �ֽ��ϴ�" << endl;
		n_Eating++;
		
		//����� �Ծ��ٸ� 
		if (n_Eating>=8)
		{
			int num = rand() % 100;
			//70% Ȯ���� ���� ��ϴ�
			if (num < 70)
			{
				cout << tempOwner->GetName() << "�� ��θ��ϱ� ��ϴ�" << endl;
				state = EState::Police_Sleep;
				n_Eating = 0;

			}
			//30%Ȯ���� ���� �մϴ�
			else
			{
				cout << tempOwner->GetName() << "�� ���� ���� �մϴ�" << endl;
				state = EState::Police_OnWork;
				n_Eating = 0;
			}
		}
		
		
		break;
	case Police_Sleep:
		if(n_Sleep==0)
		cout << tempOwner->GetName() << "�� �ڰ� �ֽ��ϴ�" << endl;

		n_Sleep++;

		//����� ��ٸ� 
		if (n_Sleep >= 10)
		{
			cout << tempOwner->GetName() << "�� ���� �Ͼ���ϴ�" << endl;

			int num = rand()%100;
			//70% Ȯ���� ���� �Խ��ϴ�
			if (num < 70)
			{
				cout << tempOwner->GetName() << "�� ��ħ���� �Խ��ϴ�" << endl;
				state = EState::Police_Eating;
				n_Sleep = 0;

			}
			//30%Ȯ���� ���� �մϴ�
			else
			{
				cout << tempOwner->GetName() << "�� ���� ���� �մϴ�" << endl;
				state = EState::Police_OnWork;
				n_Sleep = 0;
			}

		}
		break;
	case Police_OnWork:

		if (n_OnWalk == 0)
		{
			cout << tempOwner->GetName() << "\" ���� ����\"" << endl;

			APseudo* target =(APseudo*) FEventManager::GetGame()->FindActor(EActorType::Pseudo);
			if (target == nullptr)cout << tempOwner->GetName() << " \"���̺� ����\"" << endl;

			auto targetComp=(AStateComponent*)(target->GetCompnent(EComponentType::StateComponent));
			switch (targetComp->GetState())
			{
				case EState::Pseudo_Preach:
					cout << "\"��Ҵ� ���!\"" << endl;
					target->BeingCaputred();

			default:
				break;
			}
		}
		n_OnWalk++;

		//���� ������
		if (n_OnWalk)
		{
			//�ڷ� ���ϴ�
			n_OnWalk = 0;
			state = EState::Police_Sleep;
			cout << tempOwner->GetName() << "�� �ǰ��ϴ� �ڷ� ���ϴ�" << endl;
		}

		break;
	
	default:
		break;
	}
	
}

 APolice * AState_Police::GetOwner()
{
	auto tempOwner = (APolice*)(Owner);
	if (tempOwner == nullptr) { cout << "SADFAFSDFASDFASDFASFD Police Casting Error" << endl; return nullptr; }
	return tempOwner;
}

void AState_Police::sendMessage()
{
}
