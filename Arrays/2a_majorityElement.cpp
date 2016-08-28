#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	
	int n,t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		vector<int> num(n);
		for(int j=0;j<n;j++)
		{
			cin>>num[j];
		}
		map<int,int> m;
		map<int,int>::iterator it;
		for(int j=0;j<n;j++)
		{
			it=m.find(num[j]);
			if(it==m.end())
				m.insert(pair<int,int>(num[j],1));
			else
				it->second+=1;
		}
		int flag=0;
		for(it=m.begin();it!=m.end();it++)
		{
			if(it->second>(n/2))
			{
				cout<<it->first<<endl;
				flag=1;
				break;
			}
		}	
		if(flag==0)
			cout<<"NO Majority Element"<<endl;

		m.clear();
		
	}
	return 0;
}