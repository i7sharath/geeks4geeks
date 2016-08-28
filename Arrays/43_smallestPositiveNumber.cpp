#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;

int smallestPositiveNumber(vector<int>& vec)
{
	int result=1;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]<=result)
			result+=vec[i];
	}
	return result;
}


int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<smallestPositiveNumber(vec)<<endl;
	}
	return 0;
}