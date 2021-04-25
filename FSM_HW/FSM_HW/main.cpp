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
	srand(static_cast<unsigned int>(time(0)));
	
	UGameSpector::GetInstance();

	UGameSpector::GetInstance()->BeginPlay();

	while (UGameSpector::GetInstance()->bIsPowerOn())
	{
		/*currentTime = GetCurrentTime()-prevTime;
		prevTime = GetCurrentTime();
		cout<<currentTime<<endl;*/
		TickTime += 66;


		UGameSpector::GetInstance()->Update(TickTime/1000);

		Sleep(66);
		if (TickTime >= 1000)TickTime = 0.0f;
	}
	
	UGameSpector::GetInstance()->EndPlay();
	UGameSpector::EndGame();

	char c;
	cout << "State Over" << endl;
	cin >> c;
	return 0;
}