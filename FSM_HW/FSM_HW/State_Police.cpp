#include "State_Police.h"
#include"GameSpector.h"
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
//State����� �ൿ�� �մϴ�
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
				state = EState::Police_OnPatrol;
				n_Eating = 0;
			}
		}
		
		
		break;
		//�ڰ� ���� �� �ൿ
	case Police_Sleep:

		//�޽����� ������ݴϴ�
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
				state = EState::Police_OnPatrol;
				n_Sleep = 0;
			}

		}
		break;

		//���� ���� �� �ൿ
	case Police_OnPatrol:
		//���� �����ϸ� ���̺� ã�� ��ĵ�մϴ�
		if (n_OnWalk == 0)
		{
			cout << tempOwner->GetName() << "\" ���� ����\"" << endl;

			APseudo* target =(APseudo*)FGameSpector::GetInstance()->FindActor(EActorType::Pseudo);
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

		//���� �ſ� ª��
		if (n_OnWalk>0)
		{
			//�ڷ� ���ϴ�
			n_OnWalk = 0;
			state = EState::Police_Sleep;
			cout << tempOwner->GetName() << "�� �ǰ��ϴ� �ڷ� ���ϴ�" << endl;
		}

		break;

		//ü�� ���¿��� �ൿ
	case EState::Police_Capture:
		//��ƾߵ� ���̺� �����մϴ�
		APseudo* target = (APseudo*)FGameSpector::GetInstance()->FindActor(EActorType::Pseudo);
		//���̺� ���ٸ�  �� ������ ���ϴ�
		if (target == nullptr)
		{
			cout << tempOwner->GetName() << " \"���̺� ����\"" << endl;

			state = EState::Police_Eating;
			break;
		}


		//���̺� �ִٸ� ���¸� üũ�մϴ�
		auto targetComp = (AStateComponent*)(target->GetCompnent(EComponentType::StateComponent));
		switch (targetComp->GetState())
		{
			//���̺� ���� ���̶�� ����ϴ�
		case EState::Pseudo_Preach:
			cout << "\"��Ҵ� ���!\"" << endl;
			target->BeingCaputred();


			//���̺� �����ϰ� ���� �ʴٸ� �� ������ ���ϴ�
		default:
		//	//cout << "�峭��ȭ��" << endl;
			state = EState::Police_Eating;
			break;
		}

		break;
	
	}
	
}

//������ �Ű� �޾��� ��  ���¿� ���� ó���˴ϴ�
void AState_Police::GetReported()
{
	cout << "======������ �Ű� ���� �ƽ��ϴ�===" << endl;
	switch (state)
	{
	case EState::Police_Sleep:
		cout << "�ڰ� �־ �� ���ϴ�" << endl;
		break;
	case EState::Police_Eating:
		cout << "���� ���ϴ�" << endl;
		state = EState::Police_Capture;
		break;
	case EState::Police_OnPatrol:
		cout << GetOwner()->GetName()<<" : �峭��ȭ ���� ������" << endl;

		break;
	}
}

APolice * AState_Police::GetOwner()
{
	auto tempOwner = (APolice*)(Owner);
	if (tempOwner == nullptr) { cout << "SADFAFSDFASDFASDFASFD Police Casting Error" << endl; return nullptr; }
	return tempOwner;
}

