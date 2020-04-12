#ifndef PERSON_H_
#define PERSON_H_


#include "AActor.h"

/*
	���� Ŭ����

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

	//�������� ���̺� �Ű��մϴ�.

	void SendReport();
	//���̺� ���� �ɾ�ɴϴ�
	void ExposedToPseudo();

};


#endif // !PERSON_H_
