#include "GameSpector.h"

#include <conio.h>



FGameSpector* FGameSpector::instance = nullptr;

void FGameSpector::BeginPlay()
{
	


	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->BeginPlay();
	}
}

void FGameSpector::Update(float DeltaTime)
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->Update(DeltaTime);
	//	actor->UpdateComponents(DeltaTime);
	}
	getUserInput();

}

void FGameSpector::EndPlay()
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->EndPlay();
		delete *it;
	}
	Actors.clear();

	delete instance;
}

//AActor * FGameSpector::FindActor(EActorType Target)
//{
//	for (auto it : Actors)
//	{
//		if (it->GetType() == Target)
//		{
//			return it;
//		}
//	}
//	return nullptr;
//}
//


void FGameSpector::getUserInput()
{
	if (_kbhit())
	{
		auto input= _getch();
		switch (input)
		{
		case 27:
			cout << "!!!!!!!!!!!!!!강제종료!!!!!!!!!!!!!!" << endl;
			bPower = false;
			break;
		
		}
	}
}
