#ifndef DIALOGUE_COMPONENT
#define DIALOGUE_COMPONENT


#include "Component.h"

/*
	대화를 출력하는 컴포넌트
	Actor의 보유 component 중 제일 마지막에 넣어서 상태를 출력하게 해야된다

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
};



#endif // !DIALOGUE_COMPONENT
