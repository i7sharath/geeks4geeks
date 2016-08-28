#include <bits/stdc++.h>

using namespace std;

string binaryToGray(string s)
{
	string ans;
	ans+=s[0];
	for(int i=1;i<s.length();i++)
	{
		ans+=to_string((ans[i-1]-'0') ^ (s[i]-'0'));
	}
	return ans;
}

int main()
{
	string s;
	cin>>s;
	string ans;
	if(s.length()==0)
		cout<<ans<<endl;
	else
		cout<<binaryToGray(s)<<endl;
	return 0;
}
