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
	gameSpector.InitGame();
	while (1)
	{
		currentTime = GetCurrentTime()-prevTime;
		prevTime = GetCurrentTime();
		cout<<currentTime<<endl;
		gameSpector.Update(currentTime);
		Sleep(1000);
	}
	return 0;
}