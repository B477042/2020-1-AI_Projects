#pragma once
#include "AActor.h"
#include <list>
//#include<vector>
/*

	������ ���°� ����� ��� �Դϴ�.

	Goal�� Start ������ ���� �ִ���
	�� ������ � ���� ���� ���ִ��� 
	���԰��� ������

	�׸��� ���� ��Ȳ�� ��� ���� �������� �˷��ݴϴ�


	����� continue, Dead�� �ֽ��ϴ�.

*/

//���� ������ ���� ������ �����ϴ� ����ü
typedef struct FRegion
{
public:
	FRegion(int n_Missionary=0, int n_Canniblas=0,bool bBoat=false) :n_Missionary(n_Missionary), n_Cannibals(n_Cannibals),bIsBoatInThere(bBoat) {}

	int GetMissionaries() { return n_Missionary; }
	int GetCannibals() { return n_Cannibals; }
	bool IsBoatInThere() { return bIsBoatInThere; }
	//��������� ���� �� �ִ� ��Ȳ���� ����ؼ� return�Ѵ�. �������<������
	bool IsKillHappend()
	{
		if (n_Missionary < n_Cannibals)return true;
		return false;
	}

private:

	int n_Missionary;
	int n_Cannibals;
	bool bIsBoatInThere;
};

class AStateNode :
	public AActor
{
	//GoalSide�� StartSide�� ����
	AStateNode(FRegion* GoalSide = nullptr, FRegion*StartSide = nullptr) :GoalSide(GoalSide), StartSide(StartSide)
	{
		//���� �Է����ڰ� ���ٸ� �ı� ��Ų��.
		if (GoalSide == nullptr || StartSide == nullptr)delete this;
		//��Ʈ �����͸� �Է����� ���� ���
		if (isBoatInBoth() || isBoatNoWhere())delete this;
		//���� ����� ��� nullptr�� �� ���̴�
		prevNode = nullptr;
		bIsAnyoneDead = false;
		JudgeResult();
	}

	//nextNodes�� ����ִٸ� leaf node�� �ȴ�.
	bool IsLeafNode() { if (nextNodes.empty())return true; return false; }
	bool IsNodeDead() { return bIsAnyoneDead; }
	virtual void BeginPlay()override;
	virtual void  EndPlay()override;

	//���� ��带 �������ݴϴ�
	void SetPrevNode(AStateNode* Other);
	//nextNodes�� newNode�� �߰��Ѵ�
	void AddNextNode(AStateNode* newNode);
	//Tree���� ��ã�⸦ �� ��, �Ÿ� ������ ����
	int GetDistance();
	//���� ��Ȳ�� ���� ����մϴ�.
	void PrintSituation();



	const AStateNode* GetPrevNode() { return prevNode; }
	const list<AStateNode*> GetNextNodes() { return nextNodes; }
	
private:

	//���� �������� �˻��ؼ� �� ��尡 � �������� �˻��Ѵ�.
	void JudgeResult();
	//Boat�� ���ʿ� �ִ��� �˻��Ѵ�. 
	bool isBoatInBoth();
	//���� �� boat�� ������ �˻��Ѵ�. ���ٸ� true
	bool isBoatNoWhere();

private:
	//���� ����
	list<AStateNode*> nextNodes;
	//���� ���
	AStateNode* prevNode;
	//���� �׾����� �Ǻ��Ѵ�
	bool bIsAnyoneDead;
	FRegion* StartSide;
	FRegion* GoalSide;
};

