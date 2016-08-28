#include <bits/stdc++.h>

using namespace std;

int matrixMultiplication(vector<int>& vec,int i,int j)
{	
	if(i==j)
		return 0;
	int minval=INT_MAX;
	int count;
	for(int k=i;k<j;k++)
	{
		count=matrixMultiplication(vec,i,k)+matrixMultiplication(vec,k+1,j)+(vec[i-1]*vec[k]*vec[j]);
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
		cout<<matrixMultiplication(vec,1,n-1)<<endl;
		testcases--;
	}
	return 0;
}
