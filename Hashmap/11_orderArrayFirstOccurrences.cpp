#include <bits/stdc++.h>

using namespace std;

void orderedArrayelementsWithFirstOccurence(vector<int>& vec,int n)
{
	vector<int> ans(n);
	map<int,int> m;
	map<int,int>:: iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find(vec[i]);
		if(it==m.end())
			m.insert(pair<int,int>(vec[i],1));
		else
			it->second+=1;
	}
	int index=0;
	for(int i=0;i<n;i++)
	{
		it=m.find(vec[i]);
		if(it!=m.end())
		{
			int s=it->second;
			for(int i=0;i<s;i++)
				ans[index++]=it->first;
			m.erase(it);
		}
	}
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
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
		orderedArrayelementsWithFirstOccurence(vec,n);
	}
	return 0;
}
