#include <bits/stdc++.h>

using namespace std;

void generateSquare(vector<vector<int> >&sq,int n)
{
	int row=n/2,col=n-1;
	int val=1;
	for(int i=0;i<n*n;i++)
	{
		if(sq[row][col]==-1)
		{
			sq[row][col]=val;
			val++;
			row=(row-1);
			if(row<0)
				row=row+n;
			else
				row=row%n;
			col=(col+1);
			if(col<0)
				col=col+n;
			else
				col=col%n;

		}
		else
		{
			row=(row+1);
			if(row<0)
				row=row+n;
			else
				row=row%n;
			col=(col-2);
			if(col<0)
				col=col+n;
			else
				col=col%n;
			sq[row][col]=val;
			val++;
			row=(row-1);
			if(row<0)
				row=row+n;
			else
				row=row%n;
			col=(col+1);
			if(col<0)
				col=col+n;
			else
				col=col%n;

		}
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int> > sq(n,vector<int>(n,-1));
	generateSquare(sq,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<sq[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}