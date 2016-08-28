#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int CheckOppositeSigns(int x,int y)
{
	return ((x ^y)<0);
}


int main()
{
	int x,y;
	cin>>x>>y;
	cout<<CheckOppositeSigns(x,y)<<endl;
	return 0;
}