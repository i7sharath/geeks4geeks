#include <bits/stdc++.h>

using namespace std;

void caesarCipher(string& s,int shift)
{
	for(int i=0;i<s.length();i++)
		s[i]=(s[i]-'a'+shift)%26 +'a';
	return;
}

int main()
{
	string s;
	cin>>s;
	int shift;
	cin>>shift;
	caesarCipher(s,shift);
	cout<<s<<endl;
	return 0;
}