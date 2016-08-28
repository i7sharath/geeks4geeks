#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void countFrequencies(vector<int>& vec)
{
	int n=vec.size()+1;
	for(int i=0;i<vec.size();i++)
	{
		if((vec[i]%n)==n-1)  
		{
			vec[0]+=n;
		}
		else
			vec[vec[i]%n]+=n;
	}
	for(int i=1;i<vec.size();i++)
	{
		cout<<vec[i]/n<<" ";
	}
	cout<<vec[0]/n<<endl;
	return;
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
		countFrequencies(vec);
	}
	return 0;
}