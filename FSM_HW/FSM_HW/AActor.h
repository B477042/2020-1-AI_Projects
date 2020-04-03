#ifndef AACTOR
#define AACTOR
#include<iostream>
#include <vector>
#include<string>
#include "Component.h"
using namespace std;

/*
	�� ��ȭ�� �����Ե� ���� Ŭ����
	������Ʈ�� ���ؼ� �۾��ϰ� �� ���̴�. 

*/


class AActor
{
public:
	AActor();
	~AActor();

	virtual void Update(float DeltaTime);
	virtual void UpdateComponents(float DeltaTime);
	void AddComponent(Component* Other);
	void SetName(string Name) { this->Name = Name; }
protected:
	void resetTimer() { ActionTimer = 0; }
	void tickTimer(float DeltaTime) { ActionTimer += DeltaTime; }
	//Timer�� ���ѽð��� �Ѿ����� üũ�Ѵ�. ���� �Ѿ��ٸ�, true�� ��ȯ�ȴ�
	bool isTimerOver() { if (ActionTimer >= LimitTime)return true; return false; }


protected:
	vector<Component*>Components;
	string Name;
	float ActionTimer;
	float LimitTime;

};



#endif // !AACTOR
