
#include <bits/stdc++.h>

using namespace std;

bool PairGivenProduct(vector<int>& vec,int n,float x)
{
	map<float,int> m;
	map<float,int>::iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find((float)vec[i]);
		if(it==m.end())
			m.insert(pair<float,int>(vec[i],1));
		else
			it->second+=1;
	}

	for(int i=0;i<n;i++)
	{
		it=m.find(x/vec[i]);
		if(it!=m.end())
		{
			if((x/vec[i])==vec[i] && it->second > 1)
				return true;
			else if((x/vec[i])!=vec[i])
				return true;
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
		int n,prod;
		cin>>n>>prod;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		bool flag=PairGivenProduct(vec,n,prod);
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}