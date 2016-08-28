#include <bits/stdc++.h>

using namespace std;

int LCS(vector<char>& vec1,int m,vector<char>& vec2,int n)
{
	if(m==0 || n==0)
		return 0;
	if(vec1[m-1]==vec2[n-1])
		return 1+LCS(vec1,m-1,vec2,n-1);
	else 
		return max(LCS(vec1,m-1,vec2,n),LCS(vec1,m,vec2,n-1));
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int m,n;
		cin>>m>>n;
		vector<char> vec1(m);
		vector<char> vec2(n);
		for(int i=0;i<m;i++)
			cin>>vec1[i];
		for(int i=0;i<n;i++)
			cin>>vec2[i];
		cout<<LCS(vec1,m,vec2,n)<<endl;
		testcases--;
	}
	return 0;
}