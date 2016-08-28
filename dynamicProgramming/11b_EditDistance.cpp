#include <bits/stdc++.h>

using namespace std;

int editDistance(vector<vector<int> >& edits,string s1,string s2,int m,int n)
{
	if(m==0)
		return edits[m][n]=n;
	if(n==0)
		return edits[m][n]=m;
	if(edits[m][n]!=-1)
		return edits[m][n];
	if(s1[m-1]==s2[n-1])
		return edits[m][n]=editDistance(edits,s1,s2,m-1,n-1);
	else 
		return edits[m][n]=1+min(editDistance(edits,s1,s2,m,n-1),min(editDistance(edits,s1,s2,m-1,n),editDistance(edits,s1,s2,m-1,n-1)));
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int m,n;
		cin>>m>>n;
		string s1,s2;
		cin>>s1>>s2;
		vector<vector<int> > edits(m+1,vector<int>(n+1,-1));
		cout<<editDistance(edits,s1,s2,m,n)<<endl;
		testcases--;
	}
	return 0;
}