#ifndef DIALOGUE_COMPONENT
#define DIALOGUE_COMPONENT


#include "Component.h"
#include "AActor.h"

/*
	��ȭ�� ����ϴ� ������Ʈ
	Actor�� ���� component �� ���� �������� �־ ���¸� ����ϰ� �ؾߵȴ�

*/

class ADialogueComponent :
	public AComponent
{
public:
	ADialogueComponent(AEntity*Owner):AComponent(Owner)
	{
		ComponentType = EComponentType::DialogueComponent;
	}
	~ADialogueComponent();
	void ReceiveMessage(AActor* Other, string* DoWhat );
};



#endif // !DIALOGUE_COMPONENT
