#include <bits/stdc++.h>

using namespace std;

void removePattern(string &s,string pattern)
{
	while(s.find(pattern)!=string::npos)
		s.replace(s.find(pattern),pattern.length(),"X");

	for(int i=1;i<s.length();i++)
	{
		if(s[i]=='X' && s[i-1]=='X')
		{
			s.erase(i,1);
			i--;
		}

	}
	return;
}


int main()
{
	string s;
	cin>>s;
	string pattern;
	cin>>pattern;
	removePattern(s,pattern);
	cout<<s<<endl;
	return 0;
}