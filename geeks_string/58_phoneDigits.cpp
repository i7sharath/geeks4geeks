#include <bits/stdc++.h>

using namespace std;

void phoneDigits(vector<int>& vec,int currdigit,string out,int n,map<int,string>& m)
{
	if(currdigit==n)
	{
		cout<<out<<" ";
		return;
	}
	
	string temp=m[vec[currdigit]];
	for(int i=0;i<temp.size();i++)
	{
		out+=temp[i];
		phoneDigits(vec,currdigit+1,out,n,m);
		out.pop_back();
		if(vec[currdigit]==0 || vec[currdigit]==1)
			return;
	}
	return ;
}


int main()
{

	int testcases;
	cin>>testcases;
	map<int,string> m;
	m[0]="";
	m[1]="";
	m[2]="abc";
	m[3]="def";
	m[4]="ghi";
	m[5]="jkl";
	m[6]="mno";
	m[7]="pqrs";
	m[8]="tuv";
	m[9]="wxyz";
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		string out;
		phoneDigits(vec,0,out,n,m);
		testcases--;
		cout<<endl;
	}
	return 0;
}