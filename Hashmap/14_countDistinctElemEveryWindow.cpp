#include <bits/stdc++.h>

using namespace std;

void countDistinct(vector<int>& vec,int n,int k)
{
	if(k>n)
		return ;
	map<int,int> m;
	map<int,int>::iterator it;
	for(int i=0;i<k;i++)
	{
		it=m.find(vec[i]);
		if(it==m.end())
			m.insert(pair<int,int>(vec[i],1));
		else
			it->second+=1;
	}
	cout<<m.size()<<endl;
	int index=0;
	for(int i=k;i<n;i++)
	{
		it=m.find(vec[index]);
		it->second-=1;
		if(it->second==0)
			m.erase(vec[index]);
		it=m.find(vec[i]);
		if(it==m.end())
			m.insert(pair<int,int>(vec[i],i));
		else
			it->second+=1;
		cout<<m.size()<<endl;
		index++;
	}
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
		int k;
		cin>>k;
		countDistinct(vec,n,k);
	}
	return 0;
}