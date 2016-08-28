#include <bits/stdc++.h>

using namespace std;

int countPairsSum(vector<int>& vec,int sum)
{
	int n=vec.size();
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
	int ans=0;
	for(int i=0;i<n;i++)
	{
		it=m.find(sum-vec[i]);
		if(it!=m.end())
		{
			ans+=it->second;
			if((sum-vec[i])==vec[i])
				ans--;
		}
	}
	return ans/2;
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
		cout<<countPairsSum(vec,k)<<endl;
	}

	return 0;
}