#include "GameSpector.h"
#include"Pseudo.h"
#include"Person.h"
#include"Police.h"
#include <conio.h>


UGameSpector*UGameSpector::instance = nullptr;

void UGameSpector::BeginPlay()
{
	
	Actors.push_back(new APseudo());
	Actors.push_back(new APolice());
	Actors.push_back(new APerson());

	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->BeginPlay();
	}
}

void UGameSpector::Update(float DeltaTime)
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{

		if (bIsPowerOn()==false)break;
		AActor* actor = *it;
		actor->Update(DeltaTime);

		CheckAllPseudo();
	//	actor->UpdateComponents(DeltaTime);
	}
	getUserInput();
//	CheckAllPseudo();
}

void UGameSpector::EndPlay()
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->EndPlay();
		delete *it;
	}
	Actors.clear();

	
}

AActor * UGameSpector::FindActor(EActorType Target)
{
	for (auto it : Actors)
	{
		if (it->GetType() == Target)
		{
			return it;
		}
	}
	return nullptr;
}


//모든 사이비 신도의 상태를 체크합니다. 만약 모든 사이비가 체포됐다면 파워를 꺼줍니다. 아니라면 파워를 켜둡니다.
void UGameSpector::CheckAllPseudo()
{
	for (auto it : Actors)
	{
		//사이비일경우
		if (it->GetType() == EActorType::Pseudo)
		{
			auto tempComp = (AStateComponent*)it->GetCompnent(EComponentType::StateComponent);
			//잡혀있는 사이비 발견
			if (tempComp->GetState() == EState::Pseudo_Captured)
			{
				//Power를 꺼버린다. 꺼버려도 다른 사이비가 있다면 괜찮을거다
				bPower = false;
			}
			//안 잡혔을 경우
			else
			{
				//안 잡힌게 있다면 켜준다
				bPower = true;
			}
		}
	}

	
}

//사용자의 입력을 받습니다.esc를 누르면 강제종료 됩니다.
void UGameSpector::getUserInput()
{
	if (_kbhit())
	{
		auto input= _getch();
		switch (input)
		{
		case 27:
			cout << "!!!!!!!!!!!!!!강제종료!!!!!!!!!!!!!!" << endl;
			bPower = false;
			break;
		
		}
	}
}
