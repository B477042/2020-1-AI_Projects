#include "GameSpector.h"
#include"Pseudo.h"
#include"Person.h"
#include"Police.h"
#include <conio.h>


FGameSpector::FGameSpector()
{
	bPower = true;
}


FGameSpector::~FGameSpector()
{
}

void FGameSpector::BeginPlay()
{
	
	Actors.push_back(new APseudo());
	Actors.push_back(new APolice());
	Actors.push_back(new APerson());

	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->BeginPlay();
	}
}

void FGameSpector::Update(float DeltaTime)
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->Update(DeltaTime);
	//	actor->UpdateComponents(DeltaTime);
	}
	cheackPower();
	CheckAllPseudo();
}

void FGameSpector::EndPlay()
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->EndPlay();
		delete *it;
	}
	Actors.clear();
}

AActor * FGameSpector::FindActor(EActorType Target)
{
	for (auto it : Actors)
	{
		if (it->GetType() == Target)
		{
			return it;
		}
	}
	return nullptr;
}

void FGameSpector::CheckAllPseudo()
{
	for (auto it : Actors)
	{
		//���̺��ϰ��
		if (it->GetType() == EActorType::Pseudo)
		{
			auto tempComp = (AStateComponent*)it->GetCompnent(EComponentType::StateComponent);
			//�����ִ� ���̺� �߰�
			if (tempComp->GetState() == EState::Pseudo_Captured)
			{
				//Power�� ��������. �������� �ٸ� ���̺� �ִٸ� �������Ŵ�
				bPower = false;
			}
			//�� ������ ���
			else
			{
				//�� ������ �ִٸ� ���ش�
				bPower = true;
			}
		}
	}

	
}

void FGameSpector::cheackPower()
{
	if (_kbhit())
	{
		auto input= _getch();
		switch (input)
		{
		case 27:
			cout << "!!!!!!!!!!!!!!��������!!!!!!!!!!!!!!" << endl;
			bPower = false;
			break;
		
		}
	}
}
