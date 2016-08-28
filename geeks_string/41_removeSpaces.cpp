#include <bits/stdc++.h>

using namespace std;

string removespaces(string s,int n)
{
	stringstream ss(s);
	string word;
	string ans;
	while(ss>>word)
		ans+=word;
	return ans;
}

int  main()
{
	int testcases;
	cin>>testcases;
	getchar();
	while(testcases)
	{
		string s;
		getline(cin,s);
		cout<<removespaces(s,s.length())<<endl;
		testcases--;
	}
	return 0;
}