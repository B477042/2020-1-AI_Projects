#ifndef GAME_SPECTOR
#define GAME_SPECTOR

#include"AActor.h"

#include"StateComponent.h"



class UGameSpector
{
private:
	UGameSpector()
	{
		bPower = true;
	}
	//UGameSpector(const UGameSpector& other);
	~UGameSpector()
	{

	}
	static UGameSpector* instance;


public:
	static UGameSpector* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new UGameSpector();
			return instance;
		}
		return instance;
	}
	//���������� ȣ���մϴ�. �� �� get instance�� ȣ���ϸ� �������� ��������ϴ�
	static void EndGame() { delete instance; }

	 void BeginPlay();
	  void Update(float DeltaTime);
	  void EndPlay();

	 AActor* FindActor(EActorType Target);
	 bool bIsPowerOn() { return bPower; }

	//������ ���� ������ ���̺� �������� üũ�Ѵ�
	void  CheckAllPseudo();
private:
	//if Esc inputted, Power down
	void getUserInput();

private:
	bool bPower;
	vector<AActor*>Actors;

};




#endif // !GAME_SPECTOR



