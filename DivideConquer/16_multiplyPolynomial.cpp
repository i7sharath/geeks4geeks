#include <bits/stdc++.h>

using namespace std;

void multpilyPolynomials(vector<int>& vec1,vector<int> vec2,int n1,int n2)
{
	vector<int> ans(n1+n2-1,0);
	for (int i = 0; i < n1; i++)
	{
		for (int j= 0; j < n2; j++)
		{
			ans[i+j]+=vec1[i]*vec2[j];
		}
	}

	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return;
}


int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n1,n2;
		cin>>n1>>n2;
		vector<int> vec1(n1);
		vector<int> vec2(n2);
		for (int i = 0; i < n1; ++i)
			cin>>vec1[i];
		for (int i = 0; i < n2; ++i)
			cin>>vec2[i];
		multpilyPolynomials(vec1,vec2,n1,n2);
		testcases--;
	}
	return 0;
}