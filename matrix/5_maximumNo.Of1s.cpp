#include <bits/stdc++.h>

using namespace std;

int firstIndex(vector<int> &vec,int start,int end)
{
	
}

void RowWithMaxOnes(vector<vector<int> > &vec,int m,int n)
{
	int maxrow=0;
	int maxones=INT_MIN;
	for(int i=0;i<m;i++)
	{
		int index=firstIndex(vec[i],0,n-1);
		if((n-index)>maxones)
		{
			maxones=(n-index);
			maxrow=i;
		}
	}
	cout<<maxrow<<endl;
	return;
}

int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int> > vec(m,vector<int>(n));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>vec[i][j];

	RowWithMaxOnes(vec,m,n);
	return 0;
}