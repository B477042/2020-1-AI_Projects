#include "Police.h"
#include "State_Police.h"
int APolice::createdCount = 0;

APolice::APolice()
{
	createdCount++;
	name = "Police" + to_string(createdCount);
	Components.push_back(new AState_Police(this));
	actorType = EActorType::Police;

}


APolice::~APolice()
{
}

void APolice::BeginPlay()
{
}

void APolice::Update(float DeltaTime)
{
	AActor::Update(DeltaTime);

	
}

void APolice::UpdateComponents(float DeltaTime)
{
	AActor::UpdateComponents(DeltaTime);
}

void APolice::EndPlay()
{
	AActor::EndPlay();
}
