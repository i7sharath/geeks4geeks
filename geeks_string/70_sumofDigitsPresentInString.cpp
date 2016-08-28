#include <bits/stdc++.h>

using namespace std;

int countSumDigits(string s,int n)
{
	int sum=0;
	int val=0;
	int i=0;
	while(i<n)
	{
		val=0;
		while(i<n && isdigit(s[i]))
		{
			val=val*10 + s[i]-'0';
			i++;
		}
		sum+=val;
		i++;
	}
	return sum;
}

int main()
{
	string s;
	cin>>s;
	cout<<countSumDigits(s,s.length())<<endl;
	return 0;
}