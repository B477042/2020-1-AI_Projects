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
//State기반의 행동을 합니다
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
				state = EState::Police_OnPatrol;
				n_Eating = 0;
			}
		}
		
		
		break;
		//자고 있을 때 행동
	case Police_Sleep:

		//메시지를 출력해줍니다
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
				state = EState::Police_OnPatrol;
				n_Sleep = 0;
			}

		}
		break;

		//순찰 중일 때 행동
	case Police_OnPatrol:
		//일을 시작하면 사이비를 찾아 스캔합니다
		if (n_OnWalk == 0)
		{
			cout << tempOwner->GetName() << "\" 엣햄 엣햄\"" << endl;

			APseudo* target =(APseudo*)FGameSpector::GetInstance()->FindActor(EActorType::Pseudo);
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

		//일은 매우 짧게
		if (n_OnWalk>0)
		{
			//자러 갑니다
			n_OnWalk = 0;
			state = EState::Police_Sleep;
			cout << tempOwner->GetName() << "가 피곤하니 자러 갑니다" << endl;
		}

		break;

		//체포 생태에서 행동
	case EState::Police_Capture:
		//잡아야될 사이비를 조사합니다
		APseudo* target = (APseudo*)FGameSpector::GetInstance()->FindActor(EActorType::Pseudo);
		//사이비가 없다면  밥 먹으러 갑니다
		if (target == nullptr)
		{
			cout << tempOwner->GetName() << " \"사이비가 없네\"" << endl;

			state = EState::Police_Eating;
			break;
		}


		//사이비가 있다면 상태를 체크합니다
		auto targetComp = (AStateComponent*)(target->GetCompnent(EComponentType::StateComponent));
		switch (targetComp->GetState())
		{
			//사이비가 포교 중이라면 잡습니다
		case EState::Pseudo_Preach:
			cout << "\"잡았다 요놈!\"" << endl;
			target->BeingCaputred();


			//사이비가 포교하고 있지 않다면 밥 먹으러 갑니다
		default:
		//	//cout << "장난전화네" << endl;
			state = EState::Police_Eating;
			break;
		}

		break;
	
	}
	
}

//경찰이 신고를 받았을 때  상태에 따라 처리됩니다
void AState_Police::GetReported()
{
	cout << "======경찰에 신고가 접수 됐습니다===" << endl;
	switch (state)
	{
	case EState::Police_Sleep:
		cout << "자고 있어서 못 갑니다" << endl;
		break;
	case EState::Police_Eating:
		cout << "지금 갑니다" << endl;
		state = EState::Police_Capture;
		break;
	case EState::Police_OnPatrol:
		cout << GetOwner()->GetName()<<" : 장난전화 하지 마세요" << endl;

		break;
	}
}

APolice * AState_Police::GetOwner()
{
	auto tempOwner = (APolice*)(Owner);
	if (tempOwner == nullptr) { cout << "SADFAFSDFASDFASDFASFD Police Casting Error" << endl; return nullptr; }
	return tempOwner;
}

