#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;


int minDistance(vector<int>& vec,int x,int y)
{
	int prev,i=0,mindist=INT_MAX;
	for(i=0;i<vec.size();i++)
	{
		if((vec[i]==x) || (vec[i]==y))
		{
			prev=i;
			break;
		}

	}

	while(i<vec.size())
	{
		if(vec[i]==x || vec[i]==y)
		{	
			if((vec[prev]!=vec[i]) && (i-prev < mindist))
			{
				mindist=i-prev;
				prev=i;
			}
			else
				prev=i;
		}
		i++;
	}
	return mindist;
}


int main()
{
	int testcases,n;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		int x,y;
		cin>>x>>y;
		cout<<minDistance(vec,x,y)<<endl;

	}
	return 0;
}