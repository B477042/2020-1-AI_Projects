
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
};
