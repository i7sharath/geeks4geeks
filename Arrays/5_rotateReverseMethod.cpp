#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

void rotateArray(vector<int>& vec ,int n,int d)
{
	reverse(vec.begin(),vec.begin()+d);

	reverse(vec.begin()+d,vec.end());
	
	reverse(vec.begin(),vec.end());
}


int main()
{
	int n,d;
	cin>>n>>d;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	rotateArray(vec,n,d);
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	return 0;
}