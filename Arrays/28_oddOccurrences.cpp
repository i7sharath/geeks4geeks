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

void oddOccurrences(vector<int>& vec)
{
	int xor2=0,x=0,y=0;
	for(int i=0;i<vec.size();i++)
		xor2=xor2 ^ vec[i];
	
	int set_bit= xor2 & ~(xor2-1);
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]& set_bit)
			x=x ^ vec[i];
		else
			y= y ^ vec[i];
	}
	cout<<x<<" "<<y<<endl;
	return;
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
		oddOccurrences(vec);
	}
	return 0;
}