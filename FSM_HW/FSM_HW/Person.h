#ifndef PERSON_H_
#define PERSON_H_


#include "AActor.h"

/*
	행인 클래스

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

};


#endif // !PERSON_H_
