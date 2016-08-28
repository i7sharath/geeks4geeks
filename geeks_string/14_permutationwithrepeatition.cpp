#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void lexicalorder(string s,string data,int last,int index)
{
	for(int i=0;i<s.size();i++)
	{
		data[index]=s[i];
		if(index==last)
			cout<<data<<endl;
		else
			lexicalorder(s,data,last,index+1);
	}
}

int main()
{
	string s,data;
	getline(cin,s,'\n');
	data=s;
	sort(s.begin(),s.end());
	lexicalorder(s,data,s.size()-1,0);
	return 0;
}