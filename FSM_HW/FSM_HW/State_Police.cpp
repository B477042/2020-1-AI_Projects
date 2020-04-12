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
		//밥먹기
	case Police_Eating:
		if(n_Eating==0)
		cout << tempOwner->GetName() << "이 밥을 먹고 있습니다" << endl;
		n_Eating++;
		
		//충분히 먹었다면 
		if (n_Eating>=8)
		{
			int num = rand() % 100;
			//70% 확률로 잠을 잡니다
			if (num < 70)
			{
				cout << tempOwner->GetName() << "가 배부르니까 잡니다" << endl;
				state = EState::Police_Sleep;
				n_Eating = 0;

			}
			//30%확률로 일을 합니다
			else
			{
				cout << tempOwner->GetName() << "가 드디어 일읗 합니다" << endl;
				state = EState::Police_OnWork;
				n_Eating = 0;
			}
		}
		
		
		break;
	case Police_Sleep:
		if(n_Sleep==0)
		cout << tempOwner->GetName() << "가 자고 있습니다" << endl;

		n_Sleep++;

		//충분히 잤다면 
		if (n_Sleep >= 10)
		{
			cout << tempOwner->GetName() << "가 드디어 일어났습니다" << endl;

			int num = rand()%100;
			//70% 확률로 밥을 먹습니다
			if (num < 70)
			{
				cout << tempOwner->GetName() << "가 아침밥을 먹습니다" << endl;
				state = EState::Police_Eating;
				n_Sleep = 0;

			}
			//30%확률로 일을 합니다
			else
			{
				cout << tempOwner->GetName() << "가 드디어 일읗 합니다" << endl;
				state = EState::Police_OnWork;
				n_Sleep = 0;
			}

		}
		break;
	case Police_OnWork:

		if (n_OnWalk == 0)
		{
			cout << tempOwner->GetName() << "\" 엣햄 엣햄\"" << endl;

			APseudo* target =(APseudo*) FEventManager::GetGame()->FindActor(EActorType::Pseudo);
			if (target == nullptr)cout << tempOwner->GetName() << " \"사이비가 없네\"" << endl;

			auto targetComp=(AStateComponent*)(target->GetCompnent(EComponentType::StateComponent));
			switch (targetComp->GetState())
			{
				case EState::Pseudo_Preach:
					cout << "\"잡았다 요놈!\"" << endl;
					target->BeingCaputred();

			default:
				break;
			}
		}
		n_OnWalk++;

		//일이 끝나면
		if (n_OnWalk)
		{
			//자러 갑니다
			n_OnWalk = 0;
			state = EState::Police_Sleep;
			cout << tempOwner->GetName() << "가 피곤하니 자러 갑니다" << endl;
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
