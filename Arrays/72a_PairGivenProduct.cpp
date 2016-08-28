#include <bits/stdc++.h>

using namespace std;

bool PairGivenProduct(vector<int>& vec,int n,int x)
{
	int prod=0;
	int flag=false;
	int i=0,j=n-1;
	sort(vec.begin(),vec.end());
	while(i<j)
	{
		prod=vec[i]*vec[j];
		if(prod==x)
			return true;
		else if(prod<x)
			i++;
		else
			j--;
	}
	int index=0;
	for(i=0;i<n;i++)
	{
		if(vec[i]<0)
		{
			index++;
		}
		else
			break;
	}
	i=0,j=index;
	while(i<j)
	{
		prod=vec[i]*vec[j];
		if(prod==x)
			return true;
		else if(prod <x)
			j--;
		else
			i++;
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