#include <bits/stdc++.h>

using namespace std;

int totalcaloriesBurnt(vector<vector<int> >& calories,int m,int n)
{
	int i=0,j=0;
	int k=m-1,l=0;
	int girl_total=0;
	int boy_total=0
	while(i<=m-1 && j<=n && k>=0 && l<=n)
	{
		if((k!=i+1 && l!=j+1) && (k!=i+1 && l!j-1)
		{
			girl_total+=calories[k][l];
			boy_total+=calories[i][j];
			
		}
	}
	return girl_total+boy_total;
}

int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int> > calories(m,vector<int>(n));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>calories[i][j];
	}

	totalcaloriesBurnt(calories,m,n);
	return 0;
}