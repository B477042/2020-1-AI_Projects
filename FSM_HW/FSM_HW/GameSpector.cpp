#include "GameSpector.h"



FGameSpector::FGameSpector()
{
}


FGameSpector::~FGameSpector()
{
}

void FGameSpector::InitGame()
{
	AActor* Shin = new AActor();
	Shin->SetName("신천지 교인 1");
	//Shin->AddComponent();
	Actors.push_back(Shin);
}

void FGameSpector::Update(float DeltaTime)
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->Update(DeltaTime);
	}
}

void FGameSpector::EndGame()
{
}
