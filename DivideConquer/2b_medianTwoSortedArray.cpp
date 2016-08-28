#include <bits/stdc++.h>

using namespace std;

int getMedian(vector<int>& vec,int n)
{
	if(n%2==0)
		return vec[n/2]+vec[n/2-1];
	else
		return vec[n/2];
}


int median(vector<int>& vec1,vector<int>& vec2)
{
	int n=vec1.size();
	if(n==0)
		return -1;
	if(n==1)
		return (vec1[0]+vec2[0])/2;
	if(n==2)
	{
		return (max(vec1[0],vec2[0])+min(vec1[1],vec2[1]))/2;
	}

	int m1=getMedian(vec1,n);
	int m2=getMedian(vec2,n);

	if(m1==m2)
		return m1;

	else if(m1<m2)
	{
		vec1.erase(vec1.begin(),vec1.begin()+n/2);
		if(n%2==0)
			vec2.erase(vec2.begin()+n/2,vec2.end());
		else
			vec2.erase(vec2.begin()+n/2+1,vec2.end());
		return median(vec1,vec2);
	}
	else
	{
		vec2.erase(vec2.begin(),vec2.begin()+n/2);	
		if(n%2==0)	
			vec1.erase(vec1.begin()+n/2,vec1.end());
		else
			vec1.erase(vec1.begin()+n/2+1,vec1.end());
		return median(vec1,vec2);
	}
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec1(n);
		vector<int> vec2(n);
		for(int i=0;i<n;i++)
			cin>>vec1[i];
		for(int i=0;i<n;i++)
			cin>>vec2[i];
		cout<<median(vec1,vec2)<<endl;
		testcases--;
	}
	return 0;
}
