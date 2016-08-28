#include <bits/stdc++.h>

using namespace std;

string printLCS(string s1,string s2,int m,int n)
{
	vector<vector<int> > lcs(m+1,vector<int>(n+1,0));

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}

	string ans;
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			ans+=s1[i-1];
			i--;
			j--;
		}
		else if(lcs[i-1][j]>=lcs[i][j-1])
			i--;
		else
			j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}


int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int m=s1.length(),n=s2.length();
	cout<<printLCS(s1,s2,m,n)<<endl;
	return 0;
}