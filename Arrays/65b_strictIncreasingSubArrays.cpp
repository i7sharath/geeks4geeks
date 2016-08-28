#include <bits/stdc++.h>

using namespace std;

int strictIncreasinbgSubArrays(vector<int>& vec)
{
	if(vec.size()==0 || vec.size()==1)
		return 0;
	int total=0;
	int i=1,n=vec.size();
	int count=1;
	while(i<n)
	{
		while(i<n && vec[i]>vec[i-1])
		{
			count++;
			i++;
		}
		total+=(count*(count-1)/2);
		count=1;
		i++;
	}
	return total;
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
		cout<<strictIncreasinbgSubArrays(vec)<<endl;
	}
	return 0;
}