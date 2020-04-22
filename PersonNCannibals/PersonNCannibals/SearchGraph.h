#pragma once
#include"StateNode.h"
#include <queue>
#include <stack>
/*
	어떻게 문제를 풀 것인지 BFS Search를 이용하여 찾아갑니다.
	StateNode를 엮어서 만든 트리에서 해답으로 찾아갑니다.


*/

class SearchGraph
{
private:
	SearchGraph(){}
	~SearchGraph(){}
	static SearchGraph* instance;
public:
	static SearchGraph*Instance()
	{
		if (instance == nullptr)
		{
			instance = new SearchGraph();
			return instance;
		}
		else
			return instance;
	}

	//그래프에 노드를 붙인다
	void BeginPlay();
	//탐색을 시작한다
	void Run();
	//탐색이 끝나고 경로를 찾았다면 결과를 출력합니다
	void ShowResult();
	//프로그렘 종료 절차에 들어갑니다. 메모리 해제에 들어갑니다
	void EndPlay();

private:
	/*
	모든 노드들이 들어있는 벡터.
	벡터를 사용한 이유는 메모리 해제할 때 이게 더 편할거 같아서 사용했습니다
	*/
	vector<AStateNode>A_Nodes;
	//탐색할 때 사용할 노드 포인터
	AStateNode* CurrentIndexNode;
	//최단거리에 위치한 노드
	AStateNode* ShortestNode;
	//첫 시작 노드
	AStateNode* StartPointNode;
	//방문해야될 노드를 담은 queue
	queue<AStateNode*>ToVisitQue;

	/*
	최단거리 노드를 찾았다면 그 노드부터 부모로 올라가면서 경로가 되는 노드들을 저장합니다. 
	다 담았다면 시작노드가 제일 위로 올라가게 되고 그것부터 꺼내면서 결과를 출력합니다
	*/
	stack<AStateNode*>ResultStack;

};

