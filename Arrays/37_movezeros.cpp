#include <iostream>
#include <vector>


using namespace std;

void moveZeroes(vector<int>& vec)
{
	int count=0;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]!=0)
			swap(vec[i-count],vec[i]);
		else 
			count++;
	}
	return;
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
		moveZeroes(vec);
		for(int i=0;i<n;i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}