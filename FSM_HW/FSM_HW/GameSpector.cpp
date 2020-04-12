#include "GameSpector.h"
#include"Pseudo.h"
#include"Person.h"
#include"Police.h"
#include <conio.h>


FGameSpector::FGameSpector()
{
	bPower = true;
}


FGameSpector::~FGameSpector()
{
}

void FGameSpector::BeginPlay()
{
	
	Actors.push_back(new APseudo());
	Actors.push_back(new APolice());

	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->BeginPlay();
	}
}

void FGameSpector::Update(float DeltaTime)
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->Update(DeltaTime);
	//	actor->UpdateComponents(DeltaTime);
	}
	cheackPower();
}

void FGameSpector::EndPlay()
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->EndPlay();
		delete *it;
	}
	Actors.clear();
}

AActor * FGameSpector::FindActor(EActorType Target)
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

void FGameSpector::cheackPower()
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
