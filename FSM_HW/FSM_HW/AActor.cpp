#include "AActor.h"



AActor::AActor()
{
	//���߿� ���� ��
	Name = "Actor";
}


AActor::~AActor()
{
	
}

void AActor::BeginPlay()
{
}

void AActor::Update(float DeltaTime)
{
	cout << Name << endl;
	

	UpdateComponents(DeltaTime);
}

void AActor::UpdateComponents(float DeltaTime)
{
	for (auto it : Components)
	{
		
		UpdateComponents(DeltaTime);
	}
}
/*
	Component�� end play�� �����Ѵ�
	�����Ҵ��� �����Ѵ�
	�����ش�. 
*/
void AActor::EndPlay()
{
	for (auto it : Components)
	{
		EndPlay();
		delete it;
	}
	Components.clear();
}


