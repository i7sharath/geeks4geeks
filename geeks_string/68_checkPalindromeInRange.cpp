#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(string s,int l,int r)
{
	string temp=s.substr(l,r-l+1);
	cout<<temp<<endl;
	string str=temp;
	reverse(str.begin(),str.end());
	if(temp==str)
		return true;
	else
		return false;
}

int main()
{
	string s;
	cin>>s;
	int queries;
	cin>>queries;
	while(queries)
	{
		int l,r;
		cin>>l>>r;
		bool flag=checkPalindrome(s,l,r);
		cout<<flag<<endl;
		queries--;
	}
	return 0;
}