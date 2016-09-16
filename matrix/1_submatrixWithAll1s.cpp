#include <bits/stdc++.h>

using namespace std;

void submatrixWithAll1s(vector<vector<int> > &vec,int m,int n)
{
	vector<vector<int> > s(m,vector<int>(n,0));
	for(int i=0;i<m;i++)
		s[i][0]=vec[i][0];
	for(int i=0;i<n;i++)
		s[0][i]=vec[0][i];

	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(vec[i][j]!=0)
				s[i][j]=min(s[i-1][j],min(s[i][j-1],s[i-1][j-1]))+1;
		}
	}

	int maxval=INT_MIN,row,col;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			if(s[i][j] > maxval)
			{
				maxval=s[i][j];
				row=i;
				col=j;
			}
	}

	int startrow=row-maxval+1;
	int startcol=col-maxval+1;
	cout<<startrow<<" "<<startcol<<endl;

	for(int i=startrow;i<startrow+maxval;i++)
	{
		for(int j=startcol;j<startcol+maxval;j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}

	return ;
}

int main()
{
	int n,m;
	cin>>m>>n;
	vector<vector<int> > vec(m,vector<int>(n));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>vec[i][j];
	submatrixWithAll1s(vec,m,n);
	return 0;
}