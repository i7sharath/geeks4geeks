#include <bits/stdc++.h>

using namespace std;

int LCS(vector<vector<int> >& lcs,vector<char>& vec1,vector<char>& vec2,int m,int n)
{
	if(m==0 || n==0)
		return lcs[m][n]=0;
	if(lcs[m][n]!=-1)
		return lcs[m][n];
	if(vec1[m-1]==vec2[n-1])
		return lcs[m][n]=1+LCS(lcs,vec1,vec2,m-1,n-1);
	else
		return lcs[m][n]=max(LCS(lcs,vec1,vec2,m-1,n),LCS(lcs,vec1,vec2,m,n-1));
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
		vector<vector<int> > lcs(m+1,vector<int>(n+1,-1));
		cout<<LCS(lcs,vec1,vec2,m,n)<<endl;
		testcases--;
	}
	return 0;
}