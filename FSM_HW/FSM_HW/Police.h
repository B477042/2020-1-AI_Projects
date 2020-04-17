#ifndef POLICE_H_
#define POLICE_H_


#include "AActor.h"
/*
	경찰 클래스

	상태)
		1) 잠 : 잠만 잡니다
			-> 리액션 : 없음.
			-> 수신 : 시민 ---신고---> 무시

		2) 먹기 : 밥을 먹습니다
			-> 리액션 : 없음.
			-> 수신 : 시민 ---신고---> 순찰(출동)

		3) 순찰 : 순찰을 돕니다.
			-> 리액션 : 시민 - 없음, 사이비 - 체포( 포교 중이라면)
			-> 수신 : 시민 ---신고---> 무시

		4) 체포 : 사이비를 체포합니다
			-> 리액션 : 없음. 


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
