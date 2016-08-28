#include <bits/stdc++.h>

using namespace std;

int  longestSubsequence(vector<int>& vec,int n)
{
	int ans=INT_MIN;
	map<int,int> m;
	map<int,int>::iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find(vec[i]);
		if(it==m.end())
			m.insert(pair<int,int>(vec[i],1));
		else
			it->second+=1;
	}
	int count=1;
	map<int,int> ::iterator myit;
	myit=m.begin();
	for(it=m.begin();it!=m.end();it++)
	{
		if(it==m.begin())
			continue;
		if(it->first==(myit->first)+1)
			count++;
		else if(count >ans)
		{
			ans=count;
			count=1;
		}
		myit=it;
	}
	return ans;
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
		cout<<longestSubsequence(vec,n)<<endl;
	}
}