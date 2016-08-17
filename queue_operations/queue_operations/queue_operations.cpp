// queue_operations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int max(queue<int>&s)
{
	vector<int>v;
	int m = s.front();
	while (s.size()>0)
	{
		if (m < s.front())
		{
			m = s.front();
			
		
		}
		v.push_back(s.front());
		s.pop();
	}
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return m;
}
int main()
{
	queue <int> s;
	s.push(5);
	s.push(3);
	s.push(1);
	s.push(7);
	s.push(4);
	//cout << s.end();
	cout << max(s) << endl;
	while (s.size() > 0)
	{
		cout << s.front() << " ";
		s.pop();

	}
	system("pause");
	return 0;
}

