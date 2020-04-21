#ifndef GAME_SPECTOR
#define GAME_SPECTOR

#include"AActor.h"
#include<conio.h>

/*
	이번엔 게임을 관찰하는 역할이 아닌 그래프를 관리하는 역할을 합니다

*/


class FGameSpector
{
private:
	FGameSpector() { bPower = true; }
	//FGameSpector(const FGameSpector& other);
	~FGameSpector() {}
	static FGameSpector* instance;


public:
	static FGameSpector* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new FGameSpector();
		}
	
			return instance;
	}


	 void BeginPlay();
	 void Update(float DeltaTime);
	 void EndPlay();

	 //AActor* FindActor(EActorType Target);
	bool bIsPowerOn() { return bPower; }


private:
	//if Esc inputted, Power down
	void getUserInput();

private:
	bool bPower;
	vector<AActor*>Actors;

};




#endif // !GAME_SPECTOR



