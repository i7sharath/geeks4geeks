#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string s,pat;
	cin>>s>>pat;
	int ind=s.find(pat,0);
	if(ind!=string::npos);
	{
		cout<<ind<<endl;
		return 0;
	} 
	return -1;
}


