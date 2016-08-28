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

bool areConsecutive(vector<int>& vec)
{
	int min=vec[0],max=vec[0];
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]< min)
			min=vec[i];
		else if(vec[i]>max)
			max=vec[i];
	}
	if((max-min+1)==vec.size())
	{
		map<int,int> m;
		map<int,int>::iterator it;
		for(int i=0;i<vec.size();i++)
		{
			it=m.find(vec[i]);
			if(it==m.end())
				m.insert(pair<int,int>(vec[i],1));
			else 
			{
				return false;
			}
		}
	}
	return true;
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
		cout<<areConsecutive(vec)<<endl;

	}
	return 0;
}