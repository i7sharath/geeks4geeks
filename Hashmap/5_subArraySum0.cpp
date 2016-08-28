#include <bits/stdc++.h>

using namespace std;

bool checkSubArraySumZero(vector<int>& vec,int n)
{
	map<int,int> m;
	map<int,int> :: iterator it;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=vec[i];
		it=m.find(sum);
		if(it==m.end())
			m.insert(pair<int,int>(sum,1));
		else
			return true;
		if(vec[i]==0 || sum==0 )
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
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		bool flag=checkSubArraySumZero(vec,n);
		if(flag)
			cout<<"True"<<endl;
		else
			cout<<"False"<<endl;
	}
	return 0;
}