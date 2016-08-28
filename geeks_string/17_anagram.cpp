#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool checkAnagram(string s1,string s2)
{
	if(s1.size()!=s2.size())
		return false;
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	if(s1==s2)
		return true;
	else
		return false;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<checkAnagram(s1,s2)<<endl;
	return 0;
}