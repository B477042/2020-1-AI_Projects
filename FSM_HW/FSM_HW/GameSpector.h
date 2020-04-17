#ifndef GAME_SPECTOR
#define GAME_SPECTOR

#include"AActor.h"

#include"StateComponent.h"



class FGameSpector
{
private:
	FGameSpector()
	{
		bPower = true;
	}
	//FGameSpector(const FGameSpector& other);
	~FGameSpector()
	{

	}
	static FGameSpector* instance;


public:
	static FGameSpector* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new FGameSpector();
			return instance;
		}
		return instance;
	}
	//마지막으로 호출합니다. 이 후 get instance를 호출하면 에러나게 만들었습니다
	static void EndGame() { delete instance; }

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



