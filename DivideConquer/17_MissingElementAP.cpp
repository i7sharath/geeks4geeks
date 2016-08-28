#include <bits/stdc++.h>

using namespace  std;

int Missing(vector<int>& vec,int diff,int start,int end)
{
	if(start>end)
		return -1;

	int mid=start+(end-start)/2;
	if(mid<end && vec[mid+1]-vec[mid]!=diff)
		return vec[mid]+diff;
	else if(mid>start && vec[mid]-vec[mid-1]!=diff)
		return vec[mid]-diff;

	else if(vec[mid]==vec[0]+mid*diff)
		return Missing(vec,diff,mid+1,end);
	else
		return Missing(vec,diff,start,mid-1);
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for (int i = 0; i < n; ++i)
			cin>>vec[i];
		int diff=(vec[n-1]-vec[0])/n;
		cout<<Missing(vec,diff,0,n-1)<<endl;
		testcases--;
	}

	return 0;
}
