#ifndef POLICE_H_
#define POLICE_H_


#include "AActor.h"
/*
	���� Ŭ����

	����)
		1) �� : �Ḹ ��ϴ�
			-> ���׼� : ����.
			-> ���� : �ù� ---�Ű�---> ����

		2) �Ա� : ���� �Խ��ϴ�
			-> ���׼� : ����.
			-> ���� : �ù� ---�Ű�---> ����(�⵿)

		3) ���� : ������ ���ϴ�.
			-> ���׼� : �ù� - ����, ���̺� - ü��( ���� ���̶��)
			-> ���� : �ù� ---�Ű�---> ����

		4) ü�� : ���̺� ü���մϴ�
			-> ���׼� : ����. 


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
