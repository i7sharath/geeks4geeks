#include <bits/stdc++.h>

using namespace std;

void pairSumDivisibleByK(vector<int>& vec,int n,int k)
{
	map<int,int> m;
	map<int,int> :: iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find(k-vec[i]%k);
		if(it==m.end())
			m.insert(pair<int,int>(vec[i]%k,vec[i]));
		else
		{
			cout<<it->second<<" "<<vec[i]<<endl;
			m.erase(it);
		}
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
		pairSumDivisibleByK(vec,n,k);
	}
	return 0;
}