#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	
	int n,t,sum=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>sum;
		vector<int> num(n);
		for(int j=0;j<n;j++)
		{
			cin>>num[j];
		}
		map<int,int> m;
		map<int,int>::iterator it;
		int flag=0;
		for(int j=0;j<n;j++)
		{
			it=m.find(sum-num[j]);
			if(it==m.end())
				m[sum-num[i]]=1;
			else
			{
				cout<<"Yes"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"No"<<endl;
		m.clear();
		
	}
	return 0;
}