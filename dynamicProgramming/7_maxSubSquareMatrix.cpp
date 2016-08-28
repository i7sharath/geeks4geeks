#include <bits/stdc++.h>

using namespace std;

void maxSubmatrix(vector<vector<int> >& mat,int m,int n)
{
	vector<vector<int> > submat(m,vector<int>(n));
	
	for(int i=0;i<m;i++)
		submat[i][0]=mat[i][0];
	
	for(int j=0;j<n;j++)
		submat[0][j]=mat[0][j];

	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(mat[i][j]!=0)
				submat[i][j]=min(submat[i][j-1],min(submat[i-1][j],submat[i-1][j-1]))+1;
			else
				submat[i][j]=0;
		}
	}

	int maxval=INT_MIN,max_i=0,max_j=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(submat[i][j] > maxval)
			{
				maxval=submat[i][j];
				max_i=i;
	 			max_j=j;
			}
		}
	}
	cout<<endl;
	for(int i=max_i-maxval+1;i<=max_i;i++)
	{
		for(int j=max_j-maxval+1;j<=max_j;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}


	return;
}


int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int m,n;
		cin>>m>>n;
		vector<vector<int> > mat(m,vector<int>(n));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
				cin>>mat[i][j];
		}
		maxSubmatrix(mat,m,n);
		testcases--;
	}
	return 0;
}