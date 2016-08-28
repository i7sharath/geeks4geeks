#include <bits/stdc++.h>

using namespace std;

int countCharacters(string s)
{
	int state=0;
	int i=0;
	int count=0;
	while(i<s.length())
	{
		if(s[i]=='\n' || s[i]==' ' || s[i]=='\t')
		{
			state=0;
		}
		else if(state==0)
		{
			state=1;
			count++;
		}
		i++;
	}
	return count;
}

int main()
{
	string s;
	getline(cin,s);
	cout<<countCharacters(s)<<endl;
	return 0;
}