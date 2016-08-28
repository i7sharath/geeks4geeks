#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n)
{
	vector<long long int> fib(n+1,-1);
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<=n;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%1000000007;
	}
	return fib[n-1];
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		cout<<fibonacci(n)<<endl;
		testcases--;
	}
	return 0;
}