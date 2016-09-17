#include <bits/stdc++.h>

using namespace std;

void printsortedOrder(vector<int>&vec,int start,int end)
{
	if(start>end)
		return;
	printsortedOrder(vec,start*2+1,end);
	cout<<vec[start]<<" ";
	printsortedOrder(vec,start*2+2,end);
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	printsortedOrder(vec,0,n-1);
	cout<<endl;
	return 0;
}