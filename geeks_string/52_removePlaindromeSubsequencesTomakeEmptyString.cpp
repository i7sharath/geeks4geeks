#include <bits/stdc++.h>

using namespace std;

int removeSubsequences(string s,int n)
{
	string temp=s;
	reverse(temp.begin(),temp.end());
	if(temp==s)
		return 1;
	else
		return 2;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		cout<<removeSubsequences(s,n)<<endl;
		testcases--;
	}
	return 0;
}