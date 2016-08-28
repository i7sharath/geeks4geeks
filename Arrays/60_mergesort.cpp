#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& vec,int l,int m,int r)
{
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
	return ;
}


void mergesort(vector<int>& vec,int l,int r)
{
	if(l>=r)
		return;

	int mid=(l+r)/2;
	mergesort(vec,l,mid);
	mergesort(vec,mid+1,r);
	merge(vec,l,mid,r);
	return;
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	mergesort(vec,0,vec.size()-1);
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	return 0;
}