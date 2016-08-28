#include <bits/stdc++.h>

using namespace std;


int merge(vector<int>& vec,int l,int m,int r)
{
	int inversions=0;
	int n1=m,n2=r;
	int i=l,j=m+1;
	vector<int> ans;
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
			inversions+=(m-i+1);
			j++;
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
	return inversions;
}





int mergesort(vector<int>& vec,int start,int end)
{
	int inversions=0;
	if(start>=end)
		return inversions;
	int mid=(start+end)/2;
	inversions+=mergesort(vec,start,mid);
	inversions+=mergesort(vec,mid+1,end);
	inversions+=merge(vec,start,mid,end);
	return inversions;
}




int countInversions(vector<int>& vec)
{
	int inversions=0;
	inversions+=mergesort(vec,0,vec.size()-1);
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