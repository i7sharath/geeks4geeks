#include <bits/stdc++.h>

using namespace std;

int maxDepth(string s ,int n)
{
	int maxval=INT_MIN;
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			count++;
			if(count>maxval)
				maxval=count;
		}
		else if(s[i]==')')
			count--;
	}
	if(count!=0) 
		return -1;
	return maxval;

}

int main()
{
	string s;
	getline(cin,s);
	cout<<maxDepth(s,s.length())<<endl;
	return 0;
}