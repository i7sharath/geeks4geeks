#include <bits/stdc++.h>

using namespace std;

void orderArray(vector<int>& vec,int n)
{
	map<int,int> m;
	map<int,int>::iterator it;
	for(int i=0;i<n;i++)
		m.insert(pair<int,int>(vec[i],i));

	int index=0;
	for(it=m.begin();it!=m.end();it++)
	{
		vec[it->second]=index;
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
		orderArray(vec,n);
		for(int i=0;i<n;i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}