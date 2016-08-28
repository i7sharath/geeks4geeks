#include <bits/stdc++.h>

using namespace std;

void findCombination(string s,string out,int index)
{
	if(index==s.length())
		cout<<out<<endl;

	for(int i=index;i<s.length();i++)
		findCombination(s,out+'('+ s.substr(index,i+1-index)+')',i+1);
}

int main()
{
	string s;
	cin>>s;
	string out;
	findCombination(s,out,0);
	return 0;
}