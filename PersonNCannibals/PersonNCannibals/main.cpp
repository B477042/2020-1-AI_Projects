#include"SearchTree.h"

using namespace std;


int main()
{
	
	SearchTree::Instance()->CreateTree();
	SearchTree::Instance()->RunBFS();
	SearchTree::Instance()->RunDFS();
	

	SearchTree::Instance()->EndPlay();


	char a;
	cin >> a;
	
	


	return 0;
}