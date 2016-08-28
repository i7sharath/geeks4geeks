#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void reverse(string &s,int index)
{
	if(index>=s.size())
		return;
	reverse(s,index+1);
	cout<<s[index];
	return ;
}

int main()
{
	string s;
	getline(cin,s,'\n');
	reverse(s,0);
	return 0;
}