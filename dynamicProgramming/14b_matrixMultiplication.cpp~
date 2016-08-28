#include <bits/stdc++.h>

using namespace std;

int matrixMultiplication(vector<int>& vec,int i,int j,vector<vector<int> >& cache)
{	
	if(i==j)
		return cache[i][j]=0;
		
	if(cache[i][j]!=-1)
		return cache[i][j];
		
	int minval=INT_MAX;
	int count;
	for(int k=i;k<j;k++)
	{
		count=matrixMultiplication(vec,i,k,cache)+matrixMultiplication(vec,k+1,j,cache)+(vec[i-1]*vec[k]*vec[j]);
		if(minval>count)
			minval=count;
	}
	return  minval;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		vector<vector<int> > cache(n+1,vector<int>(n+1,-1));
		cout<<matrixMultiplication(vec,1,n-1,cache)<<endl;
		testcases--;
	}
	return 0;
}
