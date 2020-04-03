#include "AActor.h"



AActor::AActor()
{
}


AActor::~AActor()
{
}

void AActor::Update(float DeltaTime)
{
	cout << Name << endl;
}

void AActor::UpdateComponents(float DeltaTime)
{
}
