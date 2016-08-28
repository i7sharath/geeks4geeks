#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;


bool comparestring(string x,string y)
{
	string xy=x.append(y);
	string yx=y.append(x);
	if(xy.compare(yx)==0)
		return true;
	else if(xy.compare(yx)<0)
		return false;
	else if(xy.compare(yx)>0)
		return true;
	//return xy>yx?1:0;
}



void BiggestNumber(vector<string>& vec)
{
	sort(vec.begin(),vec.end(),comparestring);
	for(int i=0;i<vec.size();i++)
			cout<<vec[i];
	cout<<endl;
	return;
}


int main()
{
	int testcases,n;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		cin>>n;
		vector<string> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		BiggestNumber(vec);
	}
	return 0;
}