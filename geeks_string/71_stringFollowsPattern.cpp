#include <bits/stdc++.h>

using namespace std;

bool checkStringFollowsPattern(string s,int len1,string pattern,int len2)
{
	if(len1<len2)
		return false;

	for(int i=0;i<len2-1;i++)
	{
		int x=pattern[i];
		int y=pattern[i+1];
		int last=s.find_last_of(s[i]);
		int first=s.find_first_of(s[i+1]);
		if(first==string::npos || last==string::npos || last>first)
			return false;
	}
	return true;
}

int main()
{
	string s,pattern;
	getline(cin,s);
	getchar();
	cin>>pattern;
	bool flag=checkStringFollowsPattern(s,s.length(),pattern,pattern.length());
	if(flag)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}