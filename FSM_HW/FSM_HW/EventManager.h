#pragma once
/*
	이벤트 처리
*/
#include"GameSpector.h"
class FEventManager
{
private:
	FEventManager();
	~FEventManager();
	static FEventManager*instance;
	static FGameSpector* gameSpector;
public:
	static FEventManager*GetInstance()
	{
		if (instance == nullptr)
			instance = new FEventManager();
		return instance;
	}
	
	static FGameSpector* GetGame()
	{
		if (gameSpector == nullptr)
			gameSpector = new FGameSpector();
		return gameSpector;
	}
	
	static void BeginPlay();
	
	static void EndPlay()
	{
		gameSpector->EndPlay();

		delete instance;
		delete gameSpector;
		instance = nullptr;
	}

	

	
	

}; 
