#ifndef GAME_SPECTOR
#define GAME_SPECTOR

#include"AActor.h"
#include"DialogueComponent.h"
#include"StateComponent.h"

class FGameSpector
{
public:
	FGameSpector();
	~FGameSpector();

public:
	
	void InitGame();
	void Update(float DeltaTime);
	void EndGame();
private:
	vector<AActor*>Actors;

};




#endif // !GAME_SPECTOR



