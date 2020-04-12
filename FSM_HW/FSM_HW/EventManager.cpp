#include "EventManager.h"
FEventManager* FEventManager::instance = nullptr;
FGameSpector* FEventManager::gameSpector = nullptr;



FEventManager::FEventManager()
{
}


FEventManager::~FEventManager()
{
}

void FEventManager::BeginPlay()
{
	srand((unsigned int)time(NULL));


	gameSpector->BeginPlay();
}
