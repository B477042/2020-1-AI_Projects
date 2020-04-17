#include<iostream>
#include<Windows.h>
#include<time.h>
#include"GameSpector.h"
//#include"EventManager.h"
using namespace std;

int main()
{
	//float prevTime = GetCurrentTime();
	float TickTime = 0;
	//srand(static_cast<unsigned int>(time(0)));
	
	FGameSpector::GetInstance();

	FGameSpector::GetInstance()->BeginPlay();

	while (FGameSpector::GetInstance()->bIsPowerOn())
	{
		/*currentTime = GetCurrentTime()-prevTime;
		prevTime = GetCurrentTime();
		cout<<currentTime<<endl;*/
		TickTime += 66;


		FGameSpector::GetInstance()->Update(TickTime/1000);

		Sleep(66);
		if (TickTime >= 1000)TickTime = 0.0f;
	}
	
	FGameSpector::GetInstance()->EndPlay();
	FGameSpector::EndGame();

	char c;
	cout << "Plz any key to exit" << endl;
	cin >> c;
	return 0;
}