#ifndef AACTOR
#define AACTOR

#include <vector>

#include "Entity.h"
#include "Component.h"


/*
	�� ��ȭ�� �����Ե� ���� Ŭ����
	������Ʈ�� ���ؼ� �۾��ϰ� �� ���̴�. 

*/


class AActor:public AEntity
{
public:
	AActor();
	~AActor();
	virtual void BeginPlay();
	virtual void Update(float DeltaTime);
	virtual void UpdateComponents(float DeltaTime);
	virtual void EndPlay();
	
	string GetName() { return Name; }
protected:
	void resetTimer() { ActionTimer = 0; }
	void tickTimer(float DeltaTime) { ActionTimer += DeltaTime; }
	//Timer�� ���ѽð��� �Ѿ����� üũ�Ѵ�. ���� �Ѿ��ٸ�, true�� ��ȯ�ȴ�
	bool isTimerOver() { if (ActionTimer >= LimitTime)return true; return false; }
	

protected:
	vector<AComponent*>Components;
	EComponentType Type;
	float ActionTimer;
	float LimitTime;
	string Name;
};



#endif // !AACTOR
