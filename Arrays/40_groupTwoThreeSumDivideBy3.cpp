#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>


using namespace std;

int factorial(int n)
{
	if(n<0)
		return 1;
	else if(n==0 || n==1)
		return 1;
	else
		return n* factorial(n-1);
}


int groupTwoThreeDivideBy3(vector<int>& vec)
{
	vector<int> m(3);
	for(int i=0;i<vec.size();i++)
	{
		m[vec[i]%3]++;	
	}
	int count=0;

	//group of two pairs
	count+=((m[0]*(m[0]-1))/2);
	count+=(m[1]*m[2]);
	
	//group of three
	count+=(factorial(m[0])/(6*(factorial(m[0]-3))));
	count+=(factorial(m[1])/(6*(factorial(m[1]-3))));
	count+=(factorial(m[2])/(6*(factorial(m[2]-3))));
	count+=(m[0]*m[1]*m[2]);

	return count;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<groupTwoThreeDivideBy3(vec)<<endl;
	}
	return 0;
}