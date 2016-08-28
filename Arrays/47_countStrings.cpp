#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int countStrings(string s)
{
	int count=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1')
			count++;
	}
	count=(count*(count-1))/2;
	return count;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		string s;
		cin>>s;
		cout<<countStrings(s)<<endl;
	}
	return 0;
}