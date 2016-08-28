#include <bits/stdc++.h>

using namespace std;

void removeSpaces(string &s,int n)
{
	int i=0,j=0;
	while(i<n && s[i]==' ')
		i++;
	while(i<n)
	{
		if(s[i]=='.' && s[j-1]==' ')
		{
			j--;
			s[j++]=s[i];
		}
		else if(s[i]==' ' && s[j-1]!=' ')
			s[j++]=s[i];
		else if(s[i]!=' ' && s[i]!='.')
			s[j++]=s[i];

		i++;
	}
	s.erase(s.begin()+j,s.end());
	return;
}

int main()
{
	string s;
	getline(cin,s);
	removeSpaces(s,s.length());
	cout<<s<<endl;
	return 0;
}