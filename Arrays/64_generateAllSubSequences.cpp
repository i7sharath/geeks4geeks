#include <bits/stdc++.h>

using namespace std;

void generateAllSubsequences(vector<int>& vec)
{
	int n=vec.size();
	unsigned int opsize=pow(2,n);
	for(int counter=0;counter<opsize;counter++)
	{
		for(int j=0;j<n;j++)
		{
			if(counter & (1<<j))
				cout<<vec[j]<<" ";
		}
		cout<<endl;
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
		generateAllSubsequences(vec);
	}
	return 0;
}
