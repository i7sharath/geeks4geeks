#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int findSmallestMissing(vector<int>& vec)
{
	int i=0;
	for(i=0;i<vec.size();i++)
	{
		if(abs(vec[i])-1 < vec.size()  &&  vec[abs(vec[i])-1]>0)
			vec[abs(vec[i])-1]=-vec[abs(vec[i])-1];
	}
	for(i=0;i<vec.size();i++)
	{
		if(vec[i]>0)
			break;
	}
	return i+1;
}


void seggregatePositive(vector<int>& vec)
{
	int count=0;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]<0)
			swap(vec[i-count],vec[i]);
		else
			count++;
	}
	return ;
}

void removenegative(vector<int>& vec)
{
	int i=0;
	for(i=0;i<vec.size();i++)
	{
		if(vec[i]>=0)
			break;
	}
	vec.erase(vec.begin(),vec.begin()+i);
	return;
}


int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		seggregatePositive(vec);
		removenegative(vec);
		cout<<findSmallestMissing(vec)<<endl;
	}
	return 0;
}