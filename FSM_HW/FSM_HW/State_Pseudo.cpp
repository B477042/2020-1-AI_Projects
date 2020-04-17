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

	//채포됐으면 끝이다
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
		//전도하기
	case EState::Pseudo_Preach:

		
		
			/*	
				
			*/
		if(n_PreachCount==0)
			cout << tempOwner->GetName() <<"가  전도를 시작합니다" << endl;

		GetOwner()->SayHello();
			n_PreachCount++;
		

		//5번정도 전도하면 화장실에 간다
		if (n_PreachCount >= n_LimitPreach)
		{
			cout << tempOwner->GetName() << "가 화장실에 들어갑니다" << endl;
			state = EState::Pseudo_Toilet;
			
		}
		
		break;
		//화장실가기
	case EState::Pseudo_Toilet:
		n_PreachCount = 0;
		if (ActionTimer >= 1.0f)
			n_ToiletTime++;

	

		//3초정도 쉬었다면
		if (n_ToiletTime >= 3)
		{
			state = EState::Pseudo_Preach;
			cout << tempOwner->GetName() << "가 화장실에서 나와 다시 전도합니다" << endl;
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
