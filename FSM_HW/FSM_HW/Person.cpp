#include "Person.h"
#include "State_Person.h"
#include"GameSpector.h"
#include "Police.h"


APerson::APerson()
{
	actorType = EActorType::Person;
	name = "행인";
	Components.push_back(new AState_Person(this));
	
}


APerson::~APerson()
{
}

void APerson::BeginPlay()
{
}

void APerson::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);
}

void APerson::UpdateComponents(float DeltaTime)
{
	AActor::UpdateComponents(DeltaTime);
}

void APerson::EndPlay()
{
	AActor::EndPlay();
}

void APerson::SendReport()
{
	auto police=(APolice*)UGameSpector::GetInstance()->FindActor(EActorType::Police);
	
	cout << "도와주세요@@" << endl;
	police->GetReoprt();
}

void APerson::ExposedToPseudo()
{
	auto tempComp =(AState_Person*) GetCompnent(EComponentType::StateComponent);
	tempComp->ExposedToPseudo();

}

void APerson::ReactToPseudo()
{

	int talkNum = rand() % 5;
	switch (talkNum)
	{
	case 0:
		cout << name << "이 재수 없다고 자리를 피합니다" << endl;
		break;
	case 1:

		cout << name << "이 화를 냅니다" << endl;
		break;
	case 2:
		cout << name << "이 침을 뱉습니다" << endl;
		break;
	case 3:
		cout << name << "이 반야심경을 외웁니다" << endl;
		break;
	case 4:
		cout << name << "이 발로 찰려고 합니다" << endl;
		break;
	}

}
