#ifndef STATE_COMPONENT
#define STATE_COMPONENT


#include "Component.h"

/*
	상태에 대해 정의하는 컴포넌트

*/
class AStateComponent :
	public AComponent
{
public:
	AStateComponent();
	~AStateComponent();

};


#endif // !STATE_COMPONENT
