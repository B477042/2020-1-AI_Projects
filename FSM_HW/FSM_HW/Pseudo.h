#ifndef PSEUDO_H_
#define PSEUDO_H_
#include "AActor.h"
/*
	사이비 신자 클래스


	State :
			1) 포교 : 장소에서 지나가는 시민과 경찰에게 포교를 한다
				-> 리액션 : 시민 - 피하기 or 신고, 경찰 - 체포

			2) 화장실 : 포교하다가 쉬러 가거나, 경찰을 보고 일정 확률로 이동한다
				-> 리액션 : 시민 - 없음, 경찰 - 탐지불능

			3) 감옥 : 경찰에게 체포 됐을 때 상태. 업데이트가 끝난다
				-> 리액션 : 시민 - 없음, 경찰 - 없음

*/
class APseudo :
	public AActor
{
public:
	APseudo();
	~APseudo();

	virtual void BeginPlay();
	virtual void Update(float DeltaTime);
	virtual void UpdateComponents(float DeltaTime);
	virtual void EndPlay();
	//경찰에게 붙잡힌 상태가 됩니다
	void BeingCaputred();
	//사람들에게 인사합니다.
	void SayHello();
private:
	static int CreatedNum;
	bool bIsCaputred;



};




#endif // !PSEUDO_H_


