#include"GameSpector.h"
#
using namespace std;


int main()
{
	
	float TickTime = 0;
	FGameSpector::GetInstance();
	FGameSpector::GetInstance()->BeginPlay();
	while (FGameSpector::GetInstance()->bIsPowerOn())
	{
		TickTime += 66;


		//Sleep(66);
		if (TickTime >= 1000)TickTime = 0.0f;
	}

	FGameSpector::GetInstance()->EndPlay();

	return 0;
}