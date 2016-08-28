#include <bits/stdc++.h>

using namespace std;

int countDistinctAbsolute(vector<int>& vec)
{
	int n=vec.size();
	set<int> s;
	for(int i=0;i<n;i++)
		s.insert(abs(vec[i]));
	return s.size();
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
		cout<<countDistinctAbsolute(vec)<<endl;
	}
	return 0;
}