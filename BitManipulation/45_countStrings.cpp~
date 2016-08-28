#include <bits/stdc++.h>

using namespace std;

int countStrings(int n)
{	
	vector<int> setOne(n);
	vector<int> setZero(n);
	setOne[0]=setZero[0]=1;
	for(int i=1;i<n;i++)
	{
		setOne[i]=setOne[i-1]+setZero[i-1];
		setZero[i]=setOne[i-1];
	}
	return (1<<n) - setOne[n-1]-setZero[n-1];
}


int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		cout<<countStrings(n)<<endl;
		testcases--;
	}
	return 0;
}
