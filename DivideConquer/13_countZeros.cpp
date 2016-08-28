#include <bits/stdc++.h>

using namespace std;

int countZeros(vector<int>& vec,int start,int end)
{
	if(start>end)
		return -1;

	int mid=start+(end-start)/2;
	if(mid>start && vec[mid]==0 && vec[mid-1]==1)
		return mid;
	else if(mid<end && vec[mid]==1 && vec[mid+1]==0)
			return mid+1;

	else if(vec[mid]==0)
		return countZeros(vec,start,mid-1);
	else
		return countZeros(vec,mid+1,end);
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>vec[i];
		}
		int firstIndex=countZeros(vec,0,n-1);

		if(firstIndex==-1)
		{
			if(vec[0]==0)
				cout<<n<<endl;
			else
				cout<<"0"<<endl;
		}
		else
			cout<<(n-firstIndex)<<endl;
		testcases--;
	}
	return 0;
}