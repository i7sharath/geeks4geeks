#include <bits/stdc++.h>

using namespace std;

bool Isvalid(string s,int n)
{
	if(n<=1)
		return false;

	if(!isupper(s[0]))
		return false;

	if((s[n-1]!='.') || (s[n-1]=='.' && s[n-2]==' '))
		return false;

	for(int i=1;i<n;i++)
	{
		if(s[i]==' ' && s[i-1]==' ')
			return false;
	}

	string temp=s.substr(0,s.length()-1);
	string word;
	stringstream ss(temp);
	while(ss>>word)
	{
		if(!isalpha(word[0]))
			return false;
		for(int i=1;i<word.size();i++)
		{
			if(isupper(word[i]) || (!isalpha(word[i])))
				return false;
		}
	}
	return true;
}

int main()
{
	string s;
	getline(cin,s);
	bool flag=Isvalid(s,s.length());
	if(flag)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}