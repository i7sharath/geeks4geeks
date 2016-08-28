#include <bits/stdc++.h>

using namespace std;

int FindMissingElement(vector<int>& vec1,int n1,vector<int>& vec2,int n2)
{
	//invalid input
	if(n1!=n2-1 && n2!=n1-1)
		return -1;
	int ans=0;
	for(int i=0;i<n1;i++)
		ans=ans^vec1[i];
	for(int i=0;i<n2;i++)
		ans=ans^vec2[i];
	return ans;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n1;
		cin>>n1;
		vector<int> vec1(n1);
		for(int i=0;i<n1;i++)
			cin>>vec1[i];
		int n2;
		cin>>n2;
		vector<int> vec2(n2);
		for(int i=0;i<n2;i++)
			cin>>vec2[i];
		cout<<FindMissingElement(vec1,n1,vec2,n2)<<endl;
	}
	return 0;
}