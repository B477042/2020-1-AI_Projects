#ifndef GAME_SPECTOR
#define GAME_SPECTOR

#include"AActor.h"
#include"DialogueComponent.h"
#include"StateComponent.h"



class FGameSpector
{
public:
	FGameSpector();
	//FGameSpector(const FGameSpector& other);
	~FGameSpector();
	


public:
	
	 void BeginPlay();
	 void Update(float DeltaTime);
	 void EndPlay();

	 AActor* FindActor(EActorType Target);
	bool bIsPowerOn() { return bPower; }

	//게임의 종료 조건인 사이비가 잡혔는지 체크한다
	void  CheckAllPseudo();
private:
	//if Esc inputted, Power down
	void getUserInput();

private:
	bool bPower;
	vector<AActor*>Actors;

};




#endif // !GAME_SPECTOR



