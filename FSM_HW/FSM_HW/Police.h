#pragma once
#include "AActor.h"
/*
	���� Ŭ����

	�԰�, �ڰ�, ���ϰ�, ü���Ϸ� �⵿�մϴ�

	
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
private:
	static int createdCount;
};

