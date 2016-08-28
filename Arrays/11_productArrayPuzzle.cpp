#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
	int n,testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		cin>>n;
		vector<long int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		vector<long int> left(n);
		vector<long int> right(n);
		left[0]=1;
		right[n-1]=1;
		for(int i=1;i<n;i++)
		{
			left[i]=left[i-1]*arr[i-1];
		}
		for(int i=n-2;i>=0;i--)
		{
			right[i]=right[i+1]*arr[i+1];
		}
		for(int i=0;i<n;i++)
		{
			arr[i]=left[i]*right[i];
			cout<<arr[i]<<" ";
		}
		cout<<endl;

	}
	return 0;
}