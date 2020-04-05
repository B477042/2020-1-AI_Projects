#include "AActor.h"



AActor::AActor()
{
}


AActor::~AActor()
{
	//나중에 지울 것
	Name = "Actor";
}

void AActor::BeginPlay()
{
}

void AActor::Update(float DeltaTime)
{
	cout << Name << endl;
}

void AActor::UpdateComponents(float DeltaTime)
{
}


