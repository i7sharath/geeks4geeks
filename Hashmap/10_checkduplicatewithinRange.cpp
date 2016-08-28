#include <bits/stdc++.h>

using namespace std;

bool distanceBetweenDuplicateWithinRange(vector<int>& vec,int n,int k)
{
	map<int,int> m;
	map<int,int>:: iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find(vec[i]);
		if(it==m.end())
			m.insert(pair<int,int>(vec[i],i));
		else
		{
			if(i-(it->second) <= k)
				return true;
			else
				it->second=i;
		}
	}
	return false;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		bool flag=distanceBetweenDuplicateWithinRange(vec,n,k);
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
