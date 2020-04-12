#ifndef PSEUDO_H_
#define PSEUDO_H_
#include "AActor.h"
/*
	���̺� ���� Ŭ����


	State :
			1) ���� : ��ҿ��� �������� �ùΰ� �������� ������ �Ѵ�
				-> ���׼� : �ù� - ���ϱ� or �Ű�, ���� - ü��

			2) ȭ��� : �����ϴٰ� ���� ���ų�, ������ ���� ���� Ȯ���� �̵��Ѵ�
				-> ���׼� : �ù� - ����, ���� - Ž���Ҵ�

			3) ���� : �������� ü�� ���� �� ����. ������Ʈ�� ������
				-> ���׼� : �ù� - ����, ���� - ����

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
	//�������� ������ ���°� �˴ϴ�
	void BeingCaputred();
	//����鿡�� �λ��մϴ�.
	void SayHello();
private:
	static int CreatedNum;
	bool bIsCaputred;



};




#endif // !PSEUDO_H_


