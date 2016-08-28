#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

void divideStringNparts(string s,int n)
{
	while(s.size())
	{	
		for(int i=0;i<n;i++)
			cout<<s[i];
		cout<<endl;
		s.erase(0,n);
	}
	return ;
}

int main()
{
	string s;
	int n;
	getline(cin,s,'\n');
	cin>>n;
	n=s.size()/n;
	if((s.size()%n)!=0)
		cout<<"size of string not divided by n"<<endl;
	else
		divideStringNparts(s,n);
	return 0;
}