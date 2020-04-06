#include "GameSpector.h"
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
	AActor* Shin = new AActor();
	//Shin->SetName("신천지 교인 1");
	//Shin->AddComponent();
	Actors.push_back(Shin);


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
