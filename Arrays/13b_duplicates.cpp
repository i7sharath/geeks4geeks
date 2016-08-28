#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;


void duplicateElements(vector<int> vec)
{
	for(int i=0;i<vec.size();i++)
	{
		if(vec[abs(vec[i])] > 0)
			vec[abs(vec[i])]=-vec[abs(vec[i])];
		else
			cout<<abs(vec[i])<<" ";
	}
	return;
}


int main()
{
	int n,testcases;
	cin>>testcases>>n;
	vector<int> vec(n+2);
	for(int i=0;i<n+2;i++)
		cin>>vec[i];
	duplicateElements(vec);	
	return  0;
}