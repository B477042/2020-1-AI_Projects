#include"GameSpector.h"
#
using namespace std;


int main()
{
	
	float TickTime = 0;
	FGameSpector::GetInstance();
	FGameSpector::GetInstance()->BeginPlay();
	

	FGameSpector::GetInstance()->EndPlay();

	return 0;
}