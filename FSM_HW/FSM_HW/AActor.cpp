#include "AActor.h"



AActor::AActor()
{
}


AActor::~AActor()
{
	//���߿� ���� ��
	Name = "Actor";
}

void AActor::BeginPlay()
{
}

void AActor::Update(float DeltaTime)
{
	cout << Name << endl;
}

void AActor::UpdateComponents(float DeltaTime)
{
}


