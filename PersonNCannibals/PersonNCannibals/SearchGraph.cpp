#include "SearchGraph.h"
SearchGraph* SearchGraph::instance = nullptr;

void SearchGraph::BeginPlay()
{
	/*
	햇갈리니까 결과를 예측한 문제1에서 사용한 그래프의 노드에 이름을 붙여줍니다
	이름은  Node0부터 시작하고 시작노드는 StartNode로 합니다.
	번호 붙이는 순서는 부모 노드의 왼쪽부터 오른쪽 순으로 붙입니다.
	둘러쌓인 형태로 붙어있다면 12시 방향으로부터 시계 반대방향으로 번호를 붙입니다.

	*/
	

}

void SearchGraph::Run()
{
	//탐색을 시작합니다
	//모든 노드들을 돌면서 거리를 계산합니다. 
	//

	
}

void SearchGraph::ShowResult()
{
}

void SearchGraph::EndPlay()
{
}
