#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void checkStringIsRotation(string s1,string s2)
{
	s1=s1+s2;
	if(s1.find(s2)!=string::npos)
	{
		cout<<"is a rotation of each other"<<endl;
	}
	else
		cout<<"not a rotation"<<endl;
	return;
}


int main()
{
	string s1,s2;
	getline(cin,s1,'\n');
	getline(cin,s2,'\n');
	checkStringIsRotation(s1,s2);
	return 0;
}