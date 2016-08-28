#include <bits/stdc++.h>

using namespace std;

int findUgly(int n)
{
	int number=1;
	int count=1;
	int num;
	while(count<n)
	{
		number++;
		num=number;
		while(num>1)
		{
			if(num%2==0)
				num/=2;
			else
				break;
		}
		while(num>1)
		{
			if(num%3==0)
				num/=3;
			else
				break;
		}

		while(num>1)
		{
			if(num%5==0)
				num/=5;
			else
				break;
		}
		if(num==1)
			count++;
	}
	return number;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		cout<<findUgly(n)<<endl;
		testcases--;
	}

	return 0;
}