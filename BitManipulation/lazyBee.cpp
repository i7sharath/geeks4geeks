#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		string s;
		cin>>s;
		cout<<"Case #"<<t<<":"<<" "<<countAnswers(s)<<endl;
	}
	return 0;
}
