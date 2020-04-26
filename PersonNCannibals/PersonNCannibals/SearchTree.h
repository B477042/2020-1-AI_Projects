#pragma once
#include"StateNode.h"
#include <queue>
#include <stack>
/*
	
	StateNode를 엮어서 만든 트리를 이용합니다.


	DFS와 BFS를 사용하였습니다
*/

class SearchTree
{
private:
	SearchTree(){}
	~SearchTree(){}
	static SearchTree* instance;
public:
	static SearchTree*Instance()
	{
		if (instance == nullptr)
		{
			instance = new SearchTree();
			return instance;
		}
		else
			return instance;
	}

	//트리를 만든다
	void CreateTree();
	//BFS Search
	void RunBFS();
	
	//DFS Search
	void RunDFS();
	
	//프로그렘 종료 절차에 들어갑니다. 메모리 해제에 들어갑니다
	void EndPlay();

	//G값을 계산합니다
	int CalcGCount(AStateNode* Target);

private:
	//다음 탐색을 위해 트리를 처음 생성했을 상태로 바꿉니다
	void resetProgress();
	//탐색이 끝나고 경로를 찾았다면 결과를 출력합니다
	void showResultBFS();
	void showResultDFS();
	void startDFS(AStateNode*Start);
	/*
	모든 노드들이 들어있는 벡터.
	벡터를 사용한 이유는 메모리 해제할 때 이게 더 편할거 같아서 사용했습니다
	*/
	vector<AStateNode*>A_Nodes;
	
	//최단거리에 위치한 노드
	AStateNode* ShortestNode;
	//트리의 첫 시작 노드
	AStateNode* RootNode;
	//방문해야될 노드를 담은 queue
	queue<AStateNode*>BFS_ToVisitQue;
	//빅오
	int bigO;
	//DFS 탐색에서의 경로
	queue<AStateNode*>DFS_Paths;

};

