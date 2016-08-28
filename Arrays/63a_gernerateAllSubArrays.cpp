#include <bits/stdc++.h>

using namespace std;

void generateAllSubArrays(vector<int>& vec)
{
	int n=vec.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			for(int k=i;k<=j;k++)
				cout<<vec[k]<<" ";
			cout<<endl;
		}
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
		generateAllSubArrays(vec);
	}
	return 0;
}
