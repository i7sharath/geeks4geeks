#include <bits/stdc++.h>

using namespace std;

bool checkSubset(vector<int>& vec1,int n1,vector<int>& vec2,int n2)
{
	map<int,int> m;
	map<int,int>::iterator it;
	for(int i=0;i<n1;i++)
	{
		it=m.find(vec1[i]);
		if(it==m.end())
			m.insert(pair<int,int>(vec1[i],1));
		else
			it->second+=1;
	}

	for(int i=0;i<n2;i++)
	{
		it=m.find(vec2[i]);
		if(it==m.end())
			return false;
		else if(it->second>0)
			it->second-=1;
		else
			return 0;
	}
	return true;
}


int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n1;
		cin>>n1;
		vector<int> vec1(n1);
		for(int i=0;i<n1;i++)
			cin>>vec1[i];
		int n2;
		cin>>n2;
		vector<int> vec2(n2);
		for(int i=0;i<n2;i++)
			cin>>vec2[i];
		cout<<checkSubset(vec1,n1,vec2,n2)<<endl;
	}
	return 0;
}