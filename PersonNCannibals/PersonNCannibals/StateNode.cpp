#include "StateNode.h"


//��������
void AStateNode::EndPlay()
{
	
	delete StartSide;
	delete GoalSide;
	nextNodes.clear();
	prevNode.clear();
}
//���� ����� ���¸� �Ǵ��ؼ� bool���� �����մϴ�. ���⼭ ���� �׾�����, ��� ������� ���� �ǳԴ���
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
//newNode�� nextNodes�� �߰��Ѵ�. newnode�� ���� ��带 �ڽ����� �߰���Ų��
void AStateNode::AddNextNode(AStateNode * newNode)
{
	//������ ���� ����� ���� ��尡 ����.
	if (bIsAnyoneDead)
		return;

	//�� ����� prev�� ����
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
