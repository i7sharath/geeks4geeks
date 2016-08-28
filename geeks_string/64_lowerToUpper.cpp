#include <bits/stdc++.h>

using namespace std;

string toUpper(string s,int n)
{
	for(int i=0;i<n;i++)
	{
		if(s[i]>='a' && s[i]<='z')
			s[i]=s[i]-'a'+'A';
	}
	return s;
}

int main()
{
	string s;
	cin>>s;
	cout<<toUpper(s,s.length())<<endl;
	return 0;
}