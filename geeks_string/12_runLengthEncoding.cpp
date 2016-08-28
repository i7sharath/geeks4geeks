#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void runLengthEncoding(string s)
{
	string temp="";
	int count=0;
	int i=0;
	while(i<s.length())
	{
		temp+=s[i];
		count++;
		i++;
		while(i<s.length() && s[i]==s[i-1])
		{
			count++;
			i++;
		}
		temp+=to_string(count);
		count=0;

	}
	cout<<temp<<endl;
	return;
}

int main()
{
	string s;
	cin>>s;
	runLengthEncoding(s);
	return 0;
}
