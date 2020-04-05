#include "GameSpector.h"



FGameSpector::FGameSpector()
{
}


FGameSpector::~FGameSpector()
{
}

void FGameSpector::BeginPlay()
{
	AActor* Shin = new AActor();
	//Shin->SetName("��õ�� ���� 1");
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
	}
}

void FGameSpector::EndGame()
{
}
