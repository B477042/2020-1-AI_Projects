#pragma once
#include<iostream>
#include<vector>
using namespace std;


//class Fish
//{
//public:
//	Fish() { cout << "Fish can fly" << endl; }
//	~Fish() { cout << "Fish is down" << endl; }
//};
/*int a = 90, b = 100;
	int *pA = new int(a);
	int *pB = new int(b);

	Fish* newFish = new Fish();

	vector<int*> vec;
	vec.push_back(pA);
	vec.push_back(pB);

	cout << "Before Delete " << endl;

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << "it : " << *it << endl;
	}
	cout << "pa = " << *pA <<", adrress : "<<pA<< endl;
	cout << "pb = " << *pB << ", adrress : " << pB<<endl;
	cout << "===========\nAfter pop" << endl;

	for (int i=0;i<vec.capacity();i++)
	{
		delete vec[i];

	}


	if (!vec.empty())
	{
		cout << "Vec is not empty"<<endl;
		vec.clear();
	}

	if(pA!=nullptr)
		cout << "pa = " << *pA << ", adrress : " << pA << endl;
	if(pB!=nullptr)
		cout << "pb = " << *pB << ", adrress : " << pB << endl;

	delete newFish;
	if (newFish != nullptr)
		cout << "Fish never die" << endl;

	if (vec.empty())
	{
		cout << "Vec is empty" << endl;

	}
	/*delete pA;
	delete pB;*/
	/*if (pA != nullptr)
		cout << "pa = " << *pA << ", adrress : " << pA << endl;
	if (pB != nullptr)
		cout << "pb = " << *pB << ", adrress : " << pB << endl;*/



