#include "StateNode.h"

void AStateNode::BeginPlay()
{
	AActor::BeginPlay();
}

void AStateNode::EndPlay()
{
	AActor::EndPlay();
	delete StartSide;
	delete GoalSide;
	nextNodes.clear();
	
}

void AStateNode::JudgeResult()
{
	bIsAnyoneDead = StartSide->IsKillHappend();
	bIsAnyoneDead = GoalSide->IsKillHappend();

}

bool AStateNode::isBoatInBoth()
{
	if(GoalSide->IsBoatInThere()&&StartSide->IsBoatInThere())
		return true;
	else return false;
}

bool AStateNode::isBoatNoWhere()
{
	if (!GoalSide->IsBoatInThere() && !StartSide->IsBoatInThere())
		return true;

	return false;
}

void AStateNode::SetPrevNode(AStateNode * Other)
{
	if(Other!=nullptr)
	prevNode = Other;
}

void AStateNode::AddNextNode(AStateNode * newNode)
{
	//누군가 죽은 노드라면 다음 노드가 없다.
	if (bIsAnyoneDead)
		return;

	//새 노드의 prev를 설정
	newNode->SetPrevNode(this);

	nextNodes.push_back(newNode);
}

int AStateNode::GetDistance()
{
	//누군가 죽어버린 노드라면
	if(bIsAnyoneDead)
		return 10000;
	//아니라면  리턴1 
	return 1;

}

void AStateNode::PrintSituation()
{
	cout << "====================	==================" << endl;
	cout << "|        Goal      |  |       Start     | " << endl;
	cout << "| n_Missionary : " << GoalSide->GetMissionaries() << " |  | n_Missionary : " << StartSide->GetMissionaries() << " | " << endl;
	cout << "| n_Cannibal : " << GoalSide->GetCannibals() << "    |  | n_Cannibla : " << GoalSide->GetCannibals() << "    |" << endl;
	cout << "====================	==================" << endl << endl;
	cout << "Boat on the ";
	if (GoalSide->IsBoatInThere())cout << "Goal Side" << endl;
	else if (StartSide->IsBoatInThere())cout << "Start Side" << endl;
	 
}
