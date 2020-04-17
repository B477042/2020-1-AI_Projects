#include "State_Person.h"





AState_Person::~AState_Person()
{
}

void AState_Person::BeginPlay()
{
}

void AState_Person::Update(float DeltaTime)
{
	AStateComponent::Update(DeltaTime);
	excute();
	if (bIsTimeLimit())resetTimer();
}

void AState_Person::EndPlay()
{
}

void AState_Person::ExposedToPseudo()
{
	int num = rand() % 100;
	//71% Ȯ���� �ڸ��� ���մϴ�
	if (num <= 70)
		state = EState::Person_Runaway;
	else
		state = EState::Person_Report;

}


void AState_Person::excute()
{
	string name = GetOwner()->GetName();
	
	if(ActionTimer>=1.0f)
	switch (state)
	{
	case EState::Person_Idle:
		if(n_IdleTime==0)
		cout << name << "�� �̸����� ���ƴٴմϴ�" << endl;
		n_IdleTime++;
		
		


		break;
	case EState::Person_Runaway:

		
		//���̺񿡰� �����մϴ�
		GetOwner()->ReactToPseudo();

		state = EState::Person_Idle;
		
		break;
	case EState::Person_Report:
		GetOwner()->SendReport();
		state = EState::Person_Idle;
		break;
	}
}

APerson * AState_Person::GetOwner()
{
	auto tempOwner = (APerson*)(Owner);
	if (tempOwner == nullptr) { cout << "SADFAFSDFASDFASDFASFD Police Casting Error" << endl; return nullptr; }
	return tempOwner;
	
}
