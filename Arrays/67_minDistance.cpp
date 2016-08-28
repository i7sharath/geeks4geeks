#include <bits/stdc++.h>

using namespace std;

int minDistance(vector<int>& vec)
{
	int n=vec.size();
	int mindist=INT_MAX;
	sort(vec.begin(),vec.end());
	for(int i=1;i<n;i++)
	{
		mindist=min(mindist,vec[i]-vec[i-1]);
	}
	return mindist;
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
		cout<<minDistance(vec)<<endl;
	}
	return 0;
}