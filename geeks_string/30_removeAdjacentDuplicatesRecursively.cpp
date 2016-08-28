#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string s,int n)
{
	int i;
	string temp;
	for(i=1;i<n;i++)
	{
		if(s[i]!=s[i-1])
			temp+=s[i-1];
		else
		{
			while(s[i]==s[i-1])
				i++;
		}
	}
	temp+=s[i-1];
	if(temp.length()!=n)
		return removeDuplicates(temp,temp.length());
	else
		return temp;
}

int main()
{
	string s;
	cin>>s;
	int n=s.length();
	cout<<removeDuplicates(s,n)<<endl;
	return 0;

}

