#include"SearchGraph.h"

using namespace std;


int main()
{
	
	SearchTree::Instance()->CreateTree();
	SearchTree::Instance()->RunBFS();
	SearchTree::Instance()->RunDFS();
	

	SearchTree::Instance()->EndPlay();


	char a;
	cin >> a;
	
	//list<int>alist;
	/*if (alist.empty())
		cout << "view";

	char i;
	cin >> i;*/


	return 0;
}