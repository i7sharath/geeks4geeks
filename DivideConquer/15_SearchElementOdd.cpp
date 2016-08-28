#include <bits/stdc++.h>

using namespace std;

int Search(vector<int>& vec,int start,int end)
{
	if(start>end)
		return -1;
	if(start==end)
		return vec[start];
	int mid=start+(end-start)/2;
	if(vec[mid]>vec[mid-1] && vec[mid]<vec[mid+1])
		return vec[mid];
	else
	{
		if(mid%2==0)
		{
			if(vec[mid]==vec[mid-1])
				return Search(vec,start,mid-1);
			else
				return Search(vec,mid+1,end);
		}
		else
		{
			if(vec[mid]==vec[mid-1])
				return Search(vec,mid+1,end);
			else
				return Search(vec,start,mid-1);
		}
	}
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>vec[i];
	}
	cout<<Search(vec,0,n-1)<<endl;
	return 0;
}