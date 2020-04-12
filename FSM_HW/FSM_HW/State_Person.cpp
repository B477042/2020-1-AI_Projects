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
	//71% 확률로 자리를 피합니다
	if (num <= 70)
		state = EState::Person_Runaway;
	else
		state = EState::Person_Report;

}

void AState_Person::sendMessage()
{
}

void AState_Person::excute()
{
	string name = GetOwner()->GetName();
	if(ActionTimer>=1.0f)
	switch (state)
	{
	case EState::Person_Idle:
		if(n_IdleTime==0)
		cout << name << "이 이리저리 돌아다닙니다" << endl;
		n_IdleTime++;
		
	


		break;
	case EState::Person_Runaway:
		cout << name << "이 재수 없다고 자리를 피합니다" << endl;
		break;
	case EState::Person_Report:
		GetOwner()->SendReport();
		break;
	}
}

APerson * AState_Person::GetOwner()
{
	auto tempOwner = (APerson*)(Owner);
	if (tempOwner == nullptr) { cout << "SADFAFSDFASDFASDFASFD Police Casting Error" << endl; return nullptr; }
	return tempOwner;
	
}
