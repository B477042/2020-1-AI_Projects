#include "AActor.h"



AActor::AActor()
{
	
	name = "Actor";
	
}


AActor::~AActor()
{
	
}

void AActor::BeginPlay()
{
}

void AActor::Update(float DeltaTime)
{
	//cout << Name << endl;
	

	UpdateComponents(DeltaTime);
}

void AActor::UpdateComponents(float DeltaTime)
{
	for (auto it : Components)
	{
		
		it->Update(DeltaTime);
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
		it->EndPlay();
		delete it;
	}
	Components.clear();


}

	const AComponent * AActor::GetCompnent(EComponentType type)
	{
		for (auto it : Components)
		{
			if (it->GetComponentType() == type)return it;
		}

		return nullptr;
	}

	


