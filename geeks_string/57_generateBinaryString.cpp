#include <bits/stdc++.h>

using namespace std;

void generateStrings(string s,int index,int n)
{
	if(index==n)
	{
		cout<<s<<" ";
		return;
	}

	if(s[index]!='?')
		generateStrings(s,index+1,n);
	else
	{
		s[index]='0';
		generateStrings(s,index+1,n);
		s[index]='1';
		generateStrings(s,index+1,n);
	}
	return ;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		string s;
		cin>>s;
		generateStrings(s,0,s.size());
		testcases--;
		cout<<endl;
	}
	return 0;
}