#include "Person.h"



APerson::APerson()
{
	actorType = EActorType::Person;
}


APerson::~APerson()
{
}

void APerson::BeginPlay()
{
}

void APerson::Update(float DeltaTime)
{
}

void APerson::UpdateComponents(float DeltaTime)
{
}

void APerson::EndPlay()
{
	AActor::EndPlay();
}

void APerson::SendReport()
{
}
