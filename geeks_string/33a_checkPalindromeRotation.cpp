#include <bits/stdc++.h>

using namespace std;

int checkPalindrome(string s,int n)
{
	string str=s;
	reverse(str.begin(),str.end());
	if(s==str)
		return 1;

	str=s;
	for(int i=0;i<n;i++)
	{
		str+=str[0];
		str.erase(str.begin());
		string temp=str;
		reverse(temp.begin(),temp.end());
		if(str==temp)
			return 1;
	}
	return 0;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		string s;
		cin>>s;
		cout<<checkPalindrome(s,s.length())<<endl;	
		testcases--;
	}
	return 0;
}