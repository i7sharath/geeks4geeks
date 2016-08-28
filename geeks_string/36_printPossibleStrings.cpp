#include <bits/stdc++.h>

using namespace std;

void printStrings(string s,string buff,int i,int n)
{
	if(i==n)
	{	
		cout<<buff<<endl;
		return;
	}

	string temp=buff;
	temp+=s[i];
	printStrings(s,temp,i+1,n);

	temp=buff;
	temp+=' ';
	temp+=s[i];
	printStrings(s,temp,i+1,n);

}

int main()
{
	string s;
	cin>>s;
	string buff;
	buff+=s[0];
	printStrings(s,buff,1,s.length());
	return 0;
}