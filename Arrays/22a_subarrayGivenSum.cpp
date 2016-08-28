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

void subarraySum(vector<int> vec,int sum)
{
	int maxsum=0;
	for(int i=0;i<vec.size();i++)
	{
		maxsum=vec[i];
		for(int j=i+1;j<=vec.size();j++)
		{
			if(maxsum==sum)
			{
				cout<<"index is between "<<i<<" and "<<j-1<<endl;
				return;
			}
			if(maxsum>sum || j==vec.size())
				break;
			maxsum+=vec[j];
		}
	}
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
		int sum;
		cin>>sum;
		subarraySum(vec,sum);
	}
	return 0;
}