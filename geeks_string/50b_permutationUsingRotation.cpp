#include <bits/stdc++.h>

using namespace std;

void permutation(string s,string out)
{
	if(s.length()==0)
	{
		cout<<out<<endl;
		return;
	}

	for(int i=0;i<s.length();i++)
	{
		permutation(s.substr(1),out+s[0]);
		rotate(s.begin(),s.begin()+1,s.end());
	}
	return;
}

int main()
{
	string s;
	cin>>s;
	string out="";
	permutation(s,out);
	return 0;
}