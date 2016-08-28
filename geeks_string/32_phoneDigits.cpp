#include <bits/stdc++.h>

using namespace std;

void phoneDigits(vector<int>& vec,int currdigit,int n,map<int,vector<int> >& m,vector<vector<string> >& ans)
{
	if(currdigit==n)
	{
		
	}
}

int main()
{
	int testcases;
	cin>>testcases;
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	map<int,vector<string> > m;
	map<int,vector<string> > :: iterator it;
	m[0]="";
	m[1]="";
	m[2]="ABC";
	m[3]="DEF";
	m[4]="GHI";
	m[5]="JKL";
	m[6]="MNO";
	m[7]="PQRS";
	m[8]="TUV";
	m[9]="WXYZ";
	vector<vetor<string> > ans;
	phoneDigits(vec,0,n,m,ans);
	cout<<ans<<endl;
	return 0;
}
