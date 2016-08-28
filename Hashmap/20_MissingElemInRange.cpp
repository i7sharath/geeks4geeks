#include <bits/stdc++.h>

using namespace std;

void missingElements(std::vector<int>& vec,int n,int low,int high)
{
	map<int,int> m;
	map<int,int>::iterator it;
	for(int i=0;i<n;i++)
	{
		if(vec[i]>=low && vec[i]<=high)
			m.insert(pair<int,int>(vec[i],1));
	}

	for(int i=low;i<=high;i++)
	{
		it=m.find(i);
		if(it==m.end())
			cout<<i<<" ";
	}
	cout<<endl;
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
		int low,high;
		cin>>low>>high;
		missingElements(vec,n,low,high);
	}
	return 0;
}