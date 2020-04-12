#include "Pseudo.h"
#include"State_Pseudo.h"
#include"DialogueComponent.h"

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

	UpdateComponents(DeltaTime);
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
