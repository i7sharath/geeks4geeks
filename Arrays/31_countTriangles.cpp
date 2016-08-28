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

int countTriangles(vector<int>& vec)
{
	sort(vec.begin(),vec.end());
	int count=0;
	int i=0,j=0,k=0,n=vec.size();
	for(i=0;i<n;i++)
	{
		k=i+2;
		for(j=i+1;j<n;j++)
		{
			while(k<n && vec[k]<(vec[i]+vec[j]))
				k++;
			count+=k-j-1;	
		}

	}
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
		cout<<countTriangles(vec)<<endl;
	}
	return 0;
}