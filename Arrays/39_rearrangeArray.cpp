#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

void rearrangeArray(vector<int>& vec)
{
	int n=vec.size();
	for(int i=0;i<n;i++)
	{
		vec[i]+=(vec[vec[i]]%n)*n;
	}
	for(int i=0;i<n;i++)
	{
		vec[i]/=n;
	}
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
		rearrangeArray(vec);
		for(int i=0;i<n;i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}