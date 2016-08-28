#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) 
{
	int result=0;
    for(int i=0;i<nums.size();i++)
    {
        result ^=nums[i];
    }
    return result;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	int res=singleNumber(vec);
	cout<<res<<endl;
	return 0;
}