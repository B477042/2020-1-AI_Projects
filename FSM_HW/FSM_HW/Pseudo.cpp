#include "Pseudo.h"
#include"State_Pseudo.h"
#include"DialogueComponent.h"
#include"EventManager.h"
#include"Person.h"

int APseudo::CreatedNum = 0;
APseudo::APseudo()
{
	CreatedNum++;
	name = "Pseudo "+ to_string(CreatedNum);
	Components.push_back(new AState_Pseudo(this));
	actorType = EActorType::Pseudo;
	bIsCaputred = false;
}


APseudo::~APseudo()
{
	
}

void APseudo::BeginPlay()
{
	cout << name << "가 일어납니다" << endl;
}

void APseudo::Update(float DeltaTime)
{
	if (bIsCaputred==true)return;
	AActor::Update(DeltaTime);
	
}

void APseudo::UpdateComponents(float DeltaTime)
{
	if (bIsCaputred == true)return;

	for (auto it : Components)
	{
		it->Update(DeltaTime);
	}
}

void APseudo::EndPlay()
{
	AActor::EndPlay();
}

void APseudo::BeingCaputred()
{
	cout << "앆!!!" << endl;
	auto tempComp=(AState_Pseudo*)GetCompnent(EComponentType::StateComponent);
	if (tempComp)
	{
		tempComp->BeingCaputred();
		bIsCaputred = true;
		cout << "이제 못가" << endl;
	}
}

void APseudo::SayHello()
{
	auto tempComp = (AState_Pseudo*)GetCompnent(EComponentType::StateComponent);
	if (!tempComp)return;

	int num = rand() % 3;
	switch (num)
	{
	case 0:
		cout << name << " \"인상이 좋으세요 ^^\"" << endl;
		break;
	case 1:
		cout << name << " \"도를 아십니까^^\"" << endl;
		break;
	case 2:
		cout << name << " \"집에 복이 많으시네요 ^^\"" << endl;
		break;
	}

	auto temp = (APerson*)FEventManager::GetGame()->FindActor(EActorType::Person);
	if(temp!=nullptr)
	temp->ExposedToPseudo();

}
