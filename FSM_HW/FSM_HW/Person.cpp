#include "Person.h"
#include "State_Person.h"
#include"GameSpector.h"
#include "Police.h"


APerson::APerson()
{
	actorType = EActorType::Person;
	name = "����";
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
	
	cout << "�����ּ���@@" << endl;
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
		cout << name << "�� ��� ���ٰ� �ڸ��� ���մϴ�" << endl;
		break;
	case 1:

		cout << name << "�� ȭ�� ���ϴ�" << endl;
		break;
	case 2:
		cout << name << "�� ħ�� ����ϴ�" << endl;
		break;
	case 3:
		cout << name << "�� �ݾ߽ɰ��� �ܿ�ϴ�" << endl;
		break;
	case 4:
		cout << name << "�� �߷� ������ �մϴ�" << endl;
		break;
	}

}
