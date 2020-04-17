#ifndef PERSON_H_
#define PERSON_H_


#include "AActor.h"

/*
	시민 클래스

		상태
			1) 대기 : 기본상태 아무것도 안 합니다.
				수신 : 사이비------포교------>
			2) 도망가기 : 사이비를 피합니다.

			3) 신고하기 : 경찰에 사이비를 신고합니다
				
*/
class APerson :
	public AActor
{
public:
	APerson();
	
	~APerson();

	virtual void BeginPlay()override;
	virtual void Update(float DeltaTime)override;
	virtual void UpdateComponents(float DeltaTime);
	virtual void EndPlay()override;

	//경찰에게 사이비를 신고합니다.
	void SendReport();
	//사이비가 말을 걸어옵니다
	void ExposedToPseudo();

	//사이비에게 대응합니다.
	void ReactToPseudo();

};


#endif // !PERSON_H_
