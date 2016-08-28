#include <bits/stdc++.h>

using namespace std;

int longestSubstring(string s)
{
	int maxval=0;
	stack<int> st;
	st.push(-1);

	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
			st.push(i);
		else 
		{
			st.pop();
			if(!st.empty())
				maxval=max(maxval,i-st.top());
			else
				st.push(i);
		}
	}
	return maxval;
}

int  main()
{
	string s;
	cin>>s;
	cout<<longestSubstring(s)<<endl;
	return 0;
}