#include "GameSpector.h"



GameSpector::GameSpector()
{
}


GameSpector::~GameSpector()
{
}

void GameSpector::InitGame()
{
	AActor* Shin = new AActor();
	Shin->SetName("신천지 교인 1");
	//Shin->AddComponent();
	Actors.push_back(Shin);
}

void GameSpector::Update(float DeltaTime)
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->Update(DeltaTime);
	}
}

void GameSpector::EndGame()
{
}
