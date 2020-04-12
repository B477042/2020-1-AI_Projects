#ifndef POLICE_H_
#define POLICE_H_


#include "AActor.h"
/*
	경찰 클래스

	먹고, 자고, 일하고, 체포하러 출동합니다


*/
class APolice :
	public AActor
{
public:
	APolice();
	~APolice();

	virtual void BeginPlay()override;
	virtual void Update(float DeltaTime)override;
	virtual void UpdateComponents(float DeltaTime);
	virtual void EndPlay()override;

	void GetReoprt();
private:
	static int createdCount;
};


#endif // !POLICE_H_
