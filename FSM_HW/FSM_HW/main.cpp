#include<iostream>
#include<Windows.h>
#include<time.h>
#include"GameSpector.h"
#include"EventManager.h"
using namespace std;

int main()
{
	//float prevTime = GetCurrentTime();
	float TickTime = 0;
	//srand(static_cast<unsigned int>(time(0)));
	
	FEventManager::GetInstance();
	FEventManager::GetGame();
	FEventManager::GetGame()->BeginPlay();

	while (FEventManager::GetGame()->bIsPowerOn())
	{
		/*currentTime = GetCurrentTime()-prevTime;
		prevTime = GetCurrentTime();
		cout<<currentTime<<endl;*/
		TickTime += 66;


		FEventManager::GetGame()->Update(TickTime/1000);

		Sleep(66);
		if (TickTime >= 1000)TickTime = 0.0f;
	}
	
	FEventManager::EndPlay();
	

	return 0;
}