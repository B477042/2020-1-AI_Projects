#include "AActor.h"



AActor::AActor()
{
	//나중에 지울 것
	Name = "Actor";
}


AActor::~AActor()
{
	
}

void AActor::BeginPlay()
{
}

void AActor::Update(float DeltaTime)
{
	cout << Name << endl;
	

	UpdateComponents(DeltaTime);
}

void AActor::UpdateComponents(float DeltaTime)
{
	for (auto it : Components)
	{
		
		UpdateComponents(DeltaTime);
	}
}
/*
	Component의 end play를 수행한다
	동적할당을 해제한다
	날려준다. 
*/
void AActor::EndPlay()
{
	for (auto it : Components)
	{
		EndPlay();
		delete it;
	}
	Components.clear();
}


