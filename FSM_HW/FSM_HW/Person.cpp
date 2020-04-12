#include "Person.h"
#include "State_Person.h"
#include "EventManager.h"
#include "Police.h"


APerson::APerson()
{
	actorType = EActorType::Person;
	name = "青牢";
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
	auto police=(APolice*)FEventManager::GetGame()->FindActor(EActorType::Police);
	
	cout << "档客林技夸@@" << endl;
	police->GetReoprt();
}

void APerson::ExposedToPseudo()
{
	auto tempComp =(AState_Person*) GetCompnent(EComponentType::StateComponent);
	tempComp->ExposedToPseudo();

}
