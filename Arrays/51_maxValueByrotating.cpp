#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int maxvalue(vector<int>& vec)
{
	int n=vec.size(),total=0;
	int index=0,maxelem=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(vec[i]>maxelem)
		{
			maxelem=vec[i];
			index=i;
		}
	}
	reverse(vec.begin(),vec.begin()+index+1);
	reverse(vec.begin()+index+1,vec.end());
	reverse(vec.begin(),vec.end());
	for(int i=0;i<n;i++)
		total+=(i*vec[i]);
	return total;
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
		cout<<maxvalue(vec)<<endl;
	}
	return 0;
}