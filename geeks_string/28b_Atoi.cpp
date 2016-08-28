#include <bits/stdc++.h>

using namespace std;

bool isdigitcheck(char ch)
{
	if(ch>='0' && ch<='9')
		return true;
	else
		return false;
}

int Atoi(string s)
{
	if(s.length()==0)
		return 0;
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
		if(isdigitcheck(s[i])==false)
			return 0;
		ans=ans*10+ s[i]-'0';
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