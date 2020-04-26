#include "SearchTree.h"
SearchTree* SearchTree::instance = nullptr;

void SearchTree::CreateTree()
{
	/*
	�ް����ϱ� ����� ������ ����1���� ����� �׷����� ��忡 �̸��� �ٿ��ݴϴ�
	�̸���  Node0���� �����ϰ� ���۳��� StartNode�� �մϴ�.
	��ȣ ���̴� ������ �θ� ����� ���ʺ��� ������ ������ ���Դϴ�.
	�ѷ����� ���·� �پ��ִٸ� 12�� �������κ��� �ð� �ݴ�������� ��ȣ�� ���Դϴ�.

	*/
	//Node�����
	RootNode = new AStateNode(new FRegion(0,0,false),new FRegion(3,3,true));
	AStateNode* Node0 = new AStateNode(new FRegion(2, 0, true), new FRegion(1, 3, false));
	AStateNode* Node1 = new AStateNode(new FRegion(0, 1, true), new FRegion(3, 2, false));
	AStateNode* Node2 = new AStateNode(new FRegion(0, 2, true), new FRegion(3, 1, false));
	AStateNode* Node3 = new AStateNode(new FRegion(1, 1, true), new FRegion(2, 2, false));

	AStateNode* Node4 = new AStateNode(new FRegion(0, 1, false), new FRegion(3, 2, true));
	AStateNode* Node5 = new AStateNode(new FRegion(1, 0, false), new FRegion(2, 3, true));

	AStateNode* Node6 = new AStateNode(new FRegion(2, 1, true), new FRegion(1, 2, false)); 
	AStateNode* Node7 = new AStateNode(new FRegion(0, 3, true), new FRegion(3, 0, false));

	AStateNode* Node8 = new AStateNode(new FRegion(0, 2, false), new FRegion(3, 1, true));

	AStateNode* Node9 = new AStateNode(new FRegion(2, 2, true), new FRegion(1, 1, false));
	AStateNode* Node10 = new AStateNode(new FRegion(1, 3, true), new FRegion(2, 0, false));
	AStateNode* Node11 = new AStateNode(new FRegion(1, 2, true), new FRegion(2, 1, false));

	AStateNode* Node12 = new AStateNode(new FRegion(1, 1, false), new FRegion(2, 2, true));
	AStateNode* Node13 = new AStateNode(new FRegion(2, 1, false), new FRegion(1, 2, true));
	AStateNode* Node14 = new AStateNode(new FRegion(2, 0, false), new FRegion(1, 3, true));

	AStateNode* Node15 = new AStateNode(new FRegion(1, 2, true), new FRegion(2, 1, false));
	AStateNode* Node16 = new AStateNode(new FRegion(2, 1, true), new FRegion(1, 2, false));
	AStateNode* Node17 = new AStateNode(new FRegion(1, 3, true), new FRegion(2, 0, false));
	AStateNode* Node18 = new AStateNode(new FRegion(3, 1, true), new FRegion(0, 2, false));

	AStateNode* Node19 = new AStateNode(new FRegion(2, 1, false), new FRegion(1, 2, true));
	AStateNode* Node20 = new AStateNode(new FRegion(2, 0, false), new FRegion(1, 3, true));
	AStateNode* Node21 = new AStateNode(new FRegion(3, 0, false), new FRegion(0, 3, true));

	AStateNode* Node22 = new AStateNode(new FRegion(3, 2, true), new FRegion(0, 1, false));

	AStateNode* Node23 = new AStateNode(new FRegion(1, 2, false), new FRegion(2, 1, true));
	AStateNode* Node24 = new AStateNode(new FRegion(2, 2, false), new FRegion(1, 1, true));
	AStateNode* Node25 = new AStateNode(new FRegion(3, 1, false), new FRegion(0, 2, true));

	AStateNode* Node26 = new AStateNode(new FRegion(2, 3, true), new FRegion(1, 0, false));

	AStateNode* Node27 = new AStateNode(new FRegion(3, 3, true), new FRegion(0, 0, false));

	RootNode->SetPrevNode(nullptr);

	//��� ���� ��Ű��
	RootNode->AddNextNode(Node0);
	RootNode->AddNextNode(Node1);
	RootNode->AddNextNode(Node2);
	RootNode->AddNextNode(Node3);
	
	
	Node2->AddNextNode(Node4);
	Node3->AddNextNode(Node4);
	Node3->AddNextNode(Node5);
	

	Node4->AddNextNode(Node6);
	Node4->AddNextNode(Node7);


	Node7->AddNextNode(Node8);


	Node8->AddNextNode(Node9);
	Node8->AddNextNode(Node10);
	Node8->AddNextNode(Node11);

	
	Node9->AddNextNode(Node12);
	Node9->AddNextNode(Node13);
	Node9->AddNextNode(Node14);
	

	Node12->AddNextNode(Node15);
	Node12->AddNextNode(Node16);
	Node12->AddNextNode(Node17);
	Node12->AddNextNode(Node18);
	

	Node18->AddNextNode(Node19);
	Node18->AddNextNode(Node20);
	Node18->AddNextNode(Node21);
	

	Node21->AddNextNode(Node22);
	

	Node22->AddNextNode(Node23);
	Node22->AddNextNode(Node24);
	Node22->AddNextNode(Node25);
	

	Node24->AddNextNode(Node26);
	Node24->AddNextNode(Node27);
	

	Node25->AddNextNode(Node27);


	A_Nodes.push_back(RootNode);
	A_Nodes.push_back(Node0);
	A_Nodes.push_back(Node1);
	A_Nodes.push_back(Node2);
	A_Nodes.push_back(Node3);
	A_Nodes.push_back(Node4);
	A_Nodes.push_back(Node5);
	A_Nodes.push_back(Node6);
	A_Nodes.push_back(Node7);
	A_Nodes.push_back(Node8);
	A_Nodes.push_back(Node9);
	A_Nodes.push_back(Node10);
	A_Nodes.push_back(Node11);
	A_Nodes.push_back(Node12);
	A_Nodes.push_back(Node13);
	A_Nodes.push_back(Node14);
	A_Nodes.push_back(Node15);
	A_Nodes.push_back(Node16);
	A_Nodes.push_back(Node17);
	A_Nodes.push_back(Node18);
	A_Nodes.push_back(Node19);
	A_Nodes.push_back(Node20);
	A_Nodes.push_back(Node21);
	A_Nodes.push_back(Node22);
	A_Nodes.push_back(Node23);
	A_Nodes.push_back(Node24);
	A_Nodes.push_back(Node25);
	A_Nodes.push_back(Node26);
	A_Nodes.push_back(Node27);


	bigO = 0;
}

void SearchTree::RunBFS()
{
	//BFS�� ã��
	/*
		1) ���� ��带 ã��
		2)	ù ���κ��� �ڽ� ������ ã�Ƽ� queue�� �־��ش�
		3) queue�� �ϳ��� �����鼭 �� �ڽĳ����� queue�� �ִ´�
		4) ���� ��尡 leaf�ΰ� 
		4-1) ����� ���°� Dead�ΰ� -> �ƹ��͵� ���� �ʴ´�
		4-2) ����� ���°� Dead�� �ƴ϶�� -> �ִ� ���� �����Ѵ�.
		5) Ž���� queue�� ����� ������ �Ѵ�.

	*/
	BFS_ToVisitQue.push(RootNode);

	while (!BFS_ToVisitQue.empty())
	{
		auto popedNode = BFS_ToVisitQue.front();
		//queue�� �� ���� �� ����� ���� ��带 ������ ����Ʈ
		auto popedNextList=BFS_ToVisitQue.front()->GetNextNodes();
		//�������� �����ش�
		BFS_ToVisitQue.pop();
		//���� queue�������� ���� �湮�� ���̴�.
		popedNode->SetVisited(true);
		
		bigO++;
		//���� ������ Ž���մϴ�. null�� �ƴ϶��
		if(!popedNextList.empty())
		for ( auto it= popedNextList.begin(); it != popedNextList.end(); it++)
		{
			auto tempNode = *it;

			//�湮�ߴ� ����� �Ѿ��
			if (tempNode->IsVisted())
				continue;

			
			//�� ��尡 leaf����� ��
			if (tempNode->IsLeafNode())
			{
				//Clear������ ����� ���� ���� ã���� ���̵˴ϴ�
				if (tempNode->IsClear())
				{
					ShortestNode = tempNode;
					break;
				}
				else
				{
					tempNode->SetVisited(true);
				
				}
				continue;
			}
			else
			BFS_ToVisitQue.push(tempNode);
		}
		

	}

	cout << "====================================================\n";
	cout << "\t\t\tBFS\n";
	showResultBFS();


}



void SearchTree::RunDFS()
{
	startDFS(RootNode);
	showResultDFS();
}

void SearchTree::startDFS(AStateNode*Start)
{
	//�湮�� ���� �ִٸ� return
	if (Start->IsVisted())return;

	bigO++;

	
	Start->SetVisited(true);
	//���� ���� ��常 �ִ´�
	if(!Start->IsNodeDead())
		DFS_Paths.push(Start);
	//DFS�� ã��
	//Leaf��� return�մϴ�
	if (Start->IsLeafNode())
	{
		//ClearNode���
		if (Start->IsClear())
		{
			//�ִܰ�θ� �����մϴ�
			if(ShortestNode==nullptr)
				ShortestNode = Start;
			else
			{
				if (CalcGCount(ShortestNode) >= CalcGCount(Start))
					ShortestNode = Start;
			}
			return;
		}

		return;
	}


	if(!Start->GetNextNodes().empty())
	for (auto it : Start->GetNextNodes())
	{
		startDFS(it);
	}
}


void SearchTree::showResultBFS()
{
	stack<AStateNode*>results;
	auto tempNode = ShortestNode;
	//ó������ ����� ���� ���̴�
	while (tempNode!=RootNode)
	{
		auto prevList = tempNode->GetPrevNode();
		results.push(tempNode);
		tempNode = prevList.front();
		
	}
	results.push(RootNode);
	while (!results.empty())
	{
		results.top()->PrintSituation();
		results.pop();
	}
	cout << "big O " << bigO << endl;

	resetProgress();
}
//��������
void SearchTree::EndPlay()
{
	for (auto it : A_Nodes)
	{
		it->EndPlay();
		delete it;
	}
	A_Nodes.clear();

}

void SearchTree::resetProgress()
{
	for (auto it : A_Nodes)
		it->ResetNode();

	while (!BFS_ToVisitQue.empty())
		BFS_ToVisitQue.pop();

	ShortestNode = nullptr;
	bigO = 0;

	while (!DFS_Paths.empty())
		DFS_Paths.pop();

}

int SearchTree::CalcGCount(AStateNode* Target)
{
	int count = 0;
	auto temp = Target;
	//RootNode�� ������ ������ �÷������ϴ�
	while (temp != RootNode)
	{
		count++;
		temp=temp->GetPrevNode().front();
	}
	//while Ż�� ���� ������ 1 �����ϴ� �����ݴϴ�
	count++;


	return count;
}

void SearchTree::showResultDFS()
{
	cout << "===========================================" << endl;
	cout << "\t\t\tDFS" << endl;
	while(DFS_Paths.front()!=ShortestNode)
	{
		DFS_Paths.front()->PrintSituation();
		DFS_Paths.pop();
	}
	DFS_Paths.front()->PrintSituation();

	cout << "\nbig O " << bigO << endl;

	resetProgress();
}
