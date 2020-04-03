#ifndef COMPONENT
#define	COMPONENT

class AComponent
{
public:
	AComponent();
	~AComponent();
	virtual void InitComponent();
	virtual void Update(float DeltaTime);

protected:

};




#endif // !COMPONENT


