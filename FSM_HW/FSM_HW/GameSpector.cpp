#include "GameSpector.h"
#include"Pseudo.h"
#include"Person.h"
#include"Police.h"
#include <conio.h>


UGameSpector*UGameSpector::instance = nullptr;

void UGameSpector::BeginPlay()
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

void UGameSpector::Update(float DeltaTime)
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{

		if (bIsPowerOn()==false)break;
		AActor* actor = *it;
		actor->Update(DeltaTime);

		CheckAllPseudo();
	//	actor->UpdateComponents(DeltaTime);
	}
	getUserInput();
//	CheckAllPseudo();
}

void UGameSpector::EndPlay()
{
	for (auto it = Actors.begin(); it != Actors.end(); it++)
	{
		AActor* actor = *it;
		actor->EndPlay();
		delete *it;
	}
	Actors.clear();

	
}

AActor * UGameSpector::FindActor(EActorType Target)
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


//��� ���̺� �ŵ��� ���¸� üũ�մϴ�. ���� ��� ���̺� ü���ƴٸ� �Ŀ��� ���ݴϴ�. �ƴ϶�� �Ŀ��� �ѵӴϴ�.
void UGameSpector::CheckAllPseudo()
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

//������� �Է��� �޽��ϴ�.esc�� ������ �������� �˴ϴ�.
void UGameSpector::getUserInput()
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
