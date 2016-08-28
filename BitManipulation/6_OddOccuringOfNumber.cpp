/*Given an array of positive integers. All numbers occur even number of 
times except one number which occurs odd number of times. Find the number in O(n) time & constant spac*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void OddOccuringOfNumber(vector<int>& vec)
{
	unsigned int number=0;
	for(int i=0;i<vec.size();i++)
	{
		number=number ^ vec[i];
	}
	cout<<number<<endl;
	return;
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
	OddOccuringOfNumber(vec);
	return 0;
}