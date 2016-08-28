#include <bits/stdc++.h>

using namespace std;

void mergeInplace(vector<int>& vec1,int m,vector<int>& vec2,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(vec1[i]>vec2[j])
				swap(vec1[i],vec2[j]);
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
		int n,m;
		cin>>m;
		vector<int> vec1(m);
		
		for(int i=0;i<m;i++)
			cin>>vec1[i];
		cin>>n;
		vector<int> vec2(n);
		for(int i=0;i<n;i++)
			cin>>vec2[i];

		mergeInplace(vec1,m,vec2,n);
		
		for(int i=0;i<m;i++)
			cout<<vec1[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<vec2[i]<<" ";
		cout<<endl;
	}
	return 0;
}
