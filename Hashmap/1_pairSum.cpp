#include <bits/stdc++.h>

using namespace std;

bool checkPairSum(vector<int>& vec,int n,int sum)
{
	map<int,int> m;
	map<int,int> :: iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find(sum-vec[i]);
		if(it==m.end())
			m.insert(pair<int,int>(vec[i],1));
		else
			return true;
	}
	return false;
}


int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n,sum;
		cin>>n>>sum;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		bool flag=checkPairSum(vec,n,sum);
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
