#include <bits/stdc++.h>

using namespace std;

string prevPermutation(string s)
{
	int index=s.length()-2;
	while(index>=0)
	{
		if(s[index]>s[index+1])
			break;
		index--;
	}

	int nextmin=s[index+1];
	int minIndex=index+1;
	for(int i=index+1;i<s.length();i++)
	{
		if(s[i]>nextmin && s[i]<s[index])
		{
			minIndex=i;
			nextmin=s[i];
		}

	}

	swap(s[index],s[minIndex]);

	reverse(s.begin()+index+1,s.end());
	return s;
}

int main()
{
	string s;
	cin>>s;
	cout<<prevPermutation(s)<<endl;
	return 0;
}