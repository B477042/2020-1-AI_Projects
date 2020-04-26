#pragma once
//#include "AActor.h"
#include <list>
#include<vector>
#include<iostream>

using namespace std;


/*

	������ ���°� ����� ��� �Դϴ�.

	Goal�� Start ������ ���� �ִ���
	�� ������ � ���� ���� ���ִ��� 
	���԰��� ������

	�׸��� ���� ��Ȳ�� ��� ���� �������� �˷��ݴϴ�


	����� continue, Dead�� �ֽ��ϴ�.

*/

//���� ������ ���� ������ �����ϴ� ����ü
struct FRegion
{
public:
	FRegion(int n_Missionary=0, int n_Cannibals=0,bool bBoat=false) :n_Missionary(n_Missionary), n_Cannibals(n_Cannibals),bIsBoatInThere(bBoat) {}

	int GetMissionaries() { return n_Missionary; }
	int GetCannibals() { return n_Cannibals; }
	bool IsBoatInThere() { return bIsBoatInThere; }
	//��������� ���� �� �ִ� ��Ȳ���� ����ؼ� return�Ѵ�. �������<������
	bool IsKillHappend()
	{
		if (n_Missionary < n_Cannibals&&n_Missionary>0)return true;
		return false;
	}

private:

	int n_Missionary;
	int n_Cannibals;
	bool bIsBoatInThere;
};

class AStateNode 	
{
public:
	//GoalSide�� StartSide�� ����
	AStateNode(FRegion* GoalSide = nullptr, FRegion*StartSide = nullptr) :GoalSide(GoalSide), StartSide(StartSide)
	{
		//���� �Է����ڰ� ���ٸ� �ı� ��Ų��.
		if (GoalSide == nullptr || StartSide == nullptr)delete this;
		//��Ʈ �����͸� �Է����� ���� ���
		if (isBoatInBoth() || isBoatNoWhere())delete this;
		bIsClear = false;
		bIsAnyoneDead = false;
		judgeResult();
		bIsVisted = false;
		
	}

	//nextNodes�� ����ִٸ� leaf node�� �ȴ�.
	bool IsLeafNode() { if (nextNodes.empty())return true; return false; }
	bool IsNodeDead() { return bIsAnyoneDead; }
	bool IsVisted() { return bIsVisted; }
	bool IsClear() { return bIsClear; }
	void SetVisited(bool bResult) { bIsVisted = bResult; }

	 
	 void  EndPlay();

	//���� ��带 �������ݴϴ�
	void SetPrevNode(AStateNode* Other);
	//nextNodes�� newNode�� �߰��Ѵ�
	void AddNextNode(AStateNode* newNode);
	
	//���� ��Ȳ�� ���� ����մϴ�.
	void PrintSituation();
	//�湮����� ����ϴ�
	void ResetNode();


	const list<AStateNode*> GetPrevNode() { return prevNode; }
	const list<AStateNode*> GetNextNodes() { return nextNodes; }
	
private:

	//���� �������� �˻��ؼ� �� ��尡 � �������� �˻��Ѵ�.
	void judgeResult();
	//Boat�� ���ʿ� �ִ��� �˻��Ѵ�. 
	bool isBoatInBoth();
	//���� �� boat�� ������ �˻��Ѵ�. ���ٸ� true
	bool isBoatNoWhere();

private:
	//���� ����
	list<AStateNode*> nextNodes;
	//���� ����
	list<AStateNode*> prevNode;
	//���� �׾����� �Ǻ��Ѵ�
	bool bIsAnyoneDead;
	FRegion* StartSide;
	FRegion* GoalSide;
	bool bIsClear;
	bool bIsVisted;
};

