#include <bits/stdc++.h>

using namespace std;

int longestSpanMaxLength(vector<int>& vec1,vector<int>& vec2)
{
	int maxlen=0;
	int len=0,n=vec1.size();
	int sum1,sum2;
	for(int i=0;i<n;i++)
	{
		sum1=0;
		sum2=0;
		for(int j=i;j<n;j++)
		{
			sum1+=vec1[j];
			sum2+=vec2[j];
			if(sum1==sum2)
				maxlen=max(maxlen,j-i+1);	
		}
	}
	return maxlen;
}
int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		vector<int> vec1(n);
		for(int i=0;i<n;i++)
			cin>>vec1[i];
		vector<int> vec2(n);
		for(int i=0;i<n;i++)
			cin>>vec2[i];
		cout<<longestSpanMaxLength(vec1,vec2)<<endl;
	}
	return 0;
}