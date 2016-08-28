#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int testcases,n,d;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		cin>>n>>d;
		vector<int> num;
		for(int i=0;i<n;i++)
			cin>>num[i];
		int flag=0;
		if(d%n==0)
		{
			for(int i=0;i<n;i++)
				cout<<num[i]<<" ";
			cout<<endl;
			flag=1;
		}
		if(flag==0)
		{
			d=d%n;
			vector<int> vec;
			for(int i=d;i<n;i++)
				vec.push_back(num[i]);
			for(int i=0;i<d;i++)
				vec.push_back(num[i]);
			for(int i=0;i<n;i++)
				cout<<num[i]<<" ";
			cout<<endl;
		}


	}

}
