#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reversefunc(string &s,int start,int end)
{
	char temp;
	while(start<=end)
	{
		temp=s[start];
		s[start]=s[end];
		s[end]=temp;
		start++;
		end--;
	}
	return;
}

void reverseWords(string s)
{
	int start=0,end=0;
	int i=0;
	while(i<s.length())
	{
		start=i;
		while(s[i]!='\0' && s[i]!=' ')
		{
			i++;
		}
		end=i-1;
		reversefunc(s,start,end);

		if(i < s.length())
		{
			while(s[i]==' ')
			{
				i++;
			}
		}
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}

int main()
{
	string s;
	getline(cin,s,'\n');
	reverseWords(s);
	return 0;
}