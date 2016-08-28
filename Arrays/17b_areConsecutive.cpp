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
		int flag=0;
		for(int i=0;i<vec.size();i++)
		{
			if(vec[abs(vec[i])-min]>0)
				vec[abs(vec[i])-min]=-vec[abs(vec[i])-min];
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			return true;
	}
	return false;
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