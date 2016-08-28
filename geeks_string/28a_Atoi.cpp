/* this  Atoi donot handle  negative numbers*/ 

#include <bits/stdc++.h>

using namespace std;

int Atoi(string s)
{
	int ans=0;
	int sign=1;
	int i=0;
	if(s[0]=='-')
	{
		sign=-1;
		i++;
	}
	while(i<s.length())
	{
		ans=ans*10+s[i]-'0';
		i++;
	}
	return ans*sign;
}

int main()
{
	string s;
	cin>>s;
	cout<<Atoi(s)<<endl;
	return 0;
}