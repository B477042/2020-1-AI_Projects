#ifndef GAME_SPECTOR
#define GAME_SPECTOR

#include"AActor.h"
#include"DialogueComponent.h"
#include"StateComponent.h"

class GameSpector
{
public:
	GameSpector();
	~GameSpector();

public:
	
	void InitGame();
	void Update(float DeltaTime);
	void EndGame();
private:
	vector<AActor*>Actors;

};




#endif // !GAME_SPECTOR



