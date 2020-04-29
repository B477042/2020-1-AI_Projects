#include "StateNode.h"


//종료절차
void AStateNode::EndPlay()
{
	
	delete StartSide;
	delete GoalSide;
	nextNodes.clear();
	prevNode.clear();
}
//지금 노드의 상태를 판단해서 bool값을 지정합니다. 여기서 누가 죽었는지, 모든 사람들이 강을 건넜는지
void AStateNode::judgeResult()
{
	
	if (GoalSide->IsKillHappend() || StartSide->IsKillHappend())
		bIsAnyoneDead = true;
	else
		bIsAnyoneDead = false;

	if (GoalSide->GetCannibals() == 3 && GoalSide->GetMissionaries() == 3)
		bIsClear = true;
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
	prevNode.push_back( Other);
}
//newNode를 nextNodes에 추가한다. newnode의 이전 노드를 자신으로 추가시킨다
void AStateNode::AddNextNode(AStateNode * newNode)
{
	//누군가 죽은 노드라면 다음 노드가 없다.
	if (bIsAnyoneDead)
		return;

	//새 노드의 prev를 설정
	newNode->SetPrevNode(this);

	nextNodes.push_back(newNode);
}



void AStateNode::PrintSituation()
{
	cout << "====================	==================" << endl;
	cout << "|        Goal      |  |       Start     | " << endl;
	cout << "| n_Missionary : " << GoalSide->GetMissionaries() << " |  | n_Missionary : " << StartSide->GetMissionaries() << " | " << endl;
	cout << "| n_Cannibal : " << GoalSide->GetCannibals() << "    |  | n_Cannibla : " << StartSide->GetCannibals() << "    |" << endl;
	cout << "====================	==================" << endl << endl;
	//cout << "Boat on the ";
	if (GoalSide->IsBoatInThere())cout << "\tBoat" << endl;
	else if (StartSide->IsBoatInThere())cout << "\t\t\t\tBoat" << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	 
}

void AStateNode::ResetNode()
{
	bIsVisted = false;
}
