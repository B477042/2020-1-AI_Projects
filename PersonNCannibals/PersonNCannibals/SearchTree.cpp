#include "SearchTree.h"
SearchTree* SearchTree::instance = nullptr;

void SearchTree::CreateTree()
{
	/*
	햇갈리니까 결과를 예측한 문제1에서 사용한 그래프의 노드에 이름을 붙여줍니다
	이름은  Node0부터 시작하고 시작노드는 StartNode로 합니다.
	번호 붙이는 순서는 부모 노드의 왼쪽부터 오른쪽 순으로 붙입니다.
	둘러쌓인 형태로 붙어있다면 12시 방향으로부터 시계 반대방향으로 번호를 붙입니다.

	*/
	//Node만들기
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

	//노드 연결 시키기
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
	//BFS로 찾기
	/*
		1) 시작 노드를 찾기
		2)	첫 노드로부터 자식 노드들을 찾아서 queue에 넣어준다
		3) queue를 하나씩 꺼내면서 그 자식노드들을 queue에 넣는다
		4) 꺼낸 노드가 leaf인가 
		4-1) 노드의 상태가 Dead인가 -> 아무것도 하지 않는다
		4-2) 노드의 상태가 Dead가 아니라면 -> 최단 노드로 저장한다.
		5) 탐색을 queue가 비워질 때까지 한다.

	*/
	BFS_ToVisitQue.push(RootNode);

	while (!BFS_ToVisitQue.empty())
	{
		auto popedNode = BFS_ToVisitQue.front();
		//queue에 들어간 제일 앞 노드의 다음 노드를 연결한 리스트
		auto popedNextList=BFS_ToVisitQue.front()->GetNextNodes();
		//꺼냈으니 없애준다
		BFS_ToVisitQue.pop();
		//지금 queue에서꺼낸 노드는 방문한 것이다.
		popedNode->SetVisited(true);
		
		bigO++;
		//다음 노드들을 탐색합니다. null이 아니라면
		if(!popedNextList.empty())
		for ( auto it= popedNextList.begin(); it != popedNextList.end(); it++)
		{
			auto tempNode = *it;

			//방문했던 노드라면 넘어간다
			if (tempNode->IsVisted())
				continue;

			
			//이 노드가 leaf노드일 때
			if (tempNode->IsLeafNode())
			{
				//Clear상태의 노드라면 제일 먼저 찾은게 답이됩니다
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
	//방문한 적이 있다면 return
	if (Start->IsVisted())return;

	bigO++;

	
	Start->SetVisited(true);
	//죽지 않은 노드만 넣는다
	if(!Start->IsNodeDead())
		DFS_Paths.push(Start);
	//DFS로 찾기
	//Leaf라면 return합니다
	if (Start->IsLeafNode())
	{
		//ClearNode라면
		if (Start->IsClear())
		{
			//최단경로를 갱신합니다
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
	//처음노드는 비워져 있을 것이다
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
//종료절차
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
	//RootNode와 같아질 때까지 올려보냅니다
	while (temp != RootNode)
	{
		count++;
		temp=temp->GetPrevNode().front();
	}
	//while 탈출 조건 때문에 1 부족하니 더해줍니다
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
