#pragma once
#include"StateNode.h"
#include <queue>
#include <stack>
/*
	
	StateNode�� ��� ���� Ʈ���� �̿��մϴ�.


	DFS�� BFS�� ����Ͽ����ϴ�
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

	//Ʈ���� �����
	void CreateTree();
	//BFS Search
	void RunBFS();
	
	//DFS Search
	void RunDFS();
	
	//���α׷� ���� ������ ���ϴ�. �޸� ������ ���ϴ�
	void EndPlay();

	//G���� ����մϴ�
	int CalcGCount(AStateNode* Target);

private:
	//���� Ž���� ���� Ʈ���� ó�� �������� ���·� �ٲߴϴ�
	void resetProgress();
	//Ž���� ������ ��θ� ã�Ҵٸ� ����� ����մϴ�
	void showResultBFS();
	void showResultDFS();
	void startDFS(AStateNode*Start);
	/*
	��� ������ ����ִ� ����.
	���͸� ����� ������ �޸� ������ �� �̰� �� ���Ұ� ���Ƽ� ����߽��ϴ�
	*/
	vector<AStateNode*>A_Nodes;
	
	//�ִܰŸ��� ��ġ�� ���
	AStateNode* ShortestNode;
	//Ʈ���� ù ���� ���
	AStateNode* RootNode;
	//�湮�ؾߵ� ��带 ���� queue
	queue<AStateNode*>BFS_ToVisitQue;
	//���
	int bigO;
	//DFS Ž�������� ���
	queue<AStateNode*>DFS_Paths;

};

