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


int MaxDiff(vector<int>& vec)
{
	int diff=0,minelement=INT_MAX;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]<minelement)
			minelement=vec[i];
		else 
		{
			if((vec[i]-minelement) > diff)
				diff=(vec[i]-minelement);
		}
	}
	return diff;

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
		cout<<MaxDiff(vec)<<endl;
	}
	return 0;
}