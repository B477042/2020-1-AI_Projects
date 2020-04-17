#include "StateComponent.h"



//AStateComponent::AStateComponent()
//{
//}


AStateComponent::~AStateComponent()
{
}

void AStateComponent::BeginPlay()
{
}

void AStateComponent::Update(float DeltaTime)
{
	tickTimer(DeltaTime);

	
}

void AStateComponent::EndPlay()
{
}

