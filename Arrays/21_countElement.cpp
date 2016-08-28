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

void CountElement(vector<int>& vec, vector<int>& countelement)
{
	int count=0;
	for(int i=0;i<vec.size();i++)
	{
		count=0;
		for(int j=i+1;j<vec.size();j++)
		{
			if(vec[j]<vec[i])
				count++;
		}
		countelement[i]=count;
	}
	
	return ;
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
		vector<int> countelement(n,0);
		CountElement(vec,countelement);
		for(int i=0;i<countelement.size();i++)
			cout<<countelement[i]<<" ";
		cout<<endl;
	}
	return 0;
}