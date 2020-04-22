#pragma once
#include"StateNode.h"
#include <queue>
#include <stack>
/*
	��� ������ Ǯ ������ BFS Search�� �̿��Ͽ� ã�ư��ϴ�.
	StateNode�� ��� ���� Ʈ������ �ش����� ã�ư��ϴ�.


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

	//�׷����� ��带 ���δ�
	void BeginPlay();
	//Ž���� �����Ѵ�
	void Run();
	//Ž���� ������ ��θ� ã�Ҵٸ� ����� ����մϴ�
	void ShowResult();
	//���α׷� ���� ������ ���ϴ�. �޸� ������ ���ϴ�
	void EndPlay();

private:
	/*
	��� ������ ����ִ� ����.
	���͸� ����� ������ �޸� ������ �� �̰� �� ���Ұ� ���Ƽ� ����߽��ϴ�
	*/
	vector<AStateNode>A_Nodes;
	//Ž���� �� ����� ��� ������
	AStateNode* CurrentIndexNode;
	//�ִܰŸ��� ��ġ�� ���
	AStateNode* ShortestNode;
	//ù ���� ���
	AStateNode* StartPointNode;
	//�湮�ؾߵ� ��带 ���� queue
	queue<AStateNode*>ToVisitQue;

	/*
	�ִܰŸ� ��带 ã�Ҵٸ� �� ������ �θ�� �ö󰡸鼭 ��ΰ� �Ǵ� ������ �����մϴ�. 
	�� ��Ҵٸ� ���۳�尡 ���� ���� �ö󰡰� �ǰ� �װͺ��� �����鼭 ����� ����մϴ�
	*/
	stack<AStateNode*>ResultStack;

};

