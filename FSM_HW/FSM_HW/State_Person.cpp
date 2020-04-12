#include "State_Person.h"





AState_Person::~AState_Person()
{
}

void AState_Person::BeginPlay()
{
}

void AState_Person::Update(float DeltaTime)
{
	AStateComponent::Update(DeltaTime);

	if (bIsTimeLimit())resetTimer();
}

void AState_Person::EndPlay()
{
}

void AState_Person::sendMessage()
{
}
