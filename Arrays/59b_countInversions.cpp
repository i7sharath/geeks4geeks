/* count no of inversions (pair of 2) using merge sort*/
#include <bits/stdc++.h>

using namespace std;

int merge(vector<int>& vec,int l,int m,int r)
{

	int inver=0;
	vector<int> ans;
	int n1=m,n2=r;
	int i=l,j=m+1;
	while(i<=n1 && j<=n2)
	{
		if(vec[i]<=vec[j])
		{
			ans.push_back(vec[i]);
			i++;
		}	
		else if(vec[i]>vec[j])
		{	
			ans.push_back(vec[j]);
			j++;
			inver+=(m-i+1);	
		}
	}
	while(i<=n1)
		ans.push_back(vec[i++]);
	while(j<=n2)
		ans.push_back(vec[j++]);
	for(int i=0;i<ans.size();i++)
	{
		vec[l]=ans[i];
		l++;
	}
	return inver;
}

int mergesort(vector<int>& vec,int l,int r)
{
	int inversions=0;
	if(l>=r)
		return inversions;
	int mid=(l+r)/2;
	inversions=mergesort(vec,l,mid);
	inversions+=mergesort(vec,mid+1,r);
	inversions+=merge(vec,l,mid,r);
	return inversions;
}

int countInversions(vector<int>& vec)
{
	int inversions=0;
	inversions=mergesort(vec,0,vec.size()-1);
	return inversions;
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
		cout<<countInversions(vec)<<endl;
	}
	return 0;
}