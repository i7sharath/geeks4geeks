#include <bits/stdc++.h>

using namespace std;

string twoComplement(string s,int n)
{
	int flag=0;
	for(int i=n-1;i>=0;i--)
	{	
		if(flag==0 && s[i]=='1')
			flag=1;
		else if(flag==1)
			s[i]=(1-(s[i]-'0'))+'0';
	}
	if(flag==0)
		s='1'+s;
	return s;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		string s;
		cin>>s;
		cout<<twoComplement(s,s.length())<<endl;
		testcases--;
	}
	return 0;
}