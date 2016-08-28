
//time complexity o(n^2) and space o(1)

#include <bits/stdc++.h>

using namespace std;

int maxProductTriplet(vector<int>& vec)
{
	sort(vec.begin(),vec.end());
	int maxprod=INT_MIN,n=vec.size();
	int currprod;
	int i=0,k=n-1;
	for(i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			currprod=vec[i]*vec[j]*vec[k];
			maxprod=max(maxprod,currprod);	
		}
		
	}
	return maxprod;
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
		cout<<maxProductTriplet(vec)<<endl;
	}
	return 0;
}