#include<iostream>
#include<Windows.h>
#include<time.h>
#include"GameSpector.h"
using namespace std;

int main()
{
	float prevTime = GetCurrentTime();
	float currentTime = 0;

	FGameSpector gameSpector;
	gameSpector.BeginPlay();
	while (gameSpector.bIsPowerOn())
	{
		currentTime = GetCurrentTime()-prevTime;
		prevTime = GetCurrentTime();
		cout<<currentTime<<endl;
		gameSpector.Update(currentTime);
		Sleep(1000);
	}
	gameSpector.EndPlay();
	

	return 0;
}