
//time complexity O(nlogn) and space O(1)

#include <bits/stdc++.h>

using namespace std;

int maxProductTriplet(vector<int>& vec)
{
	sort(vec.begin(),vec.end());
	int maxprod=INT_MIN,n=vec.size();
	maxprod=max(maxprod,vec[n-1]*vec[n-2]*vec[n-3]);
	maxprod=max(maxprod,vec[0]*vec[1]*vec[n-1]);
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