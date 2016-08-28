#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int square(int n)
{
	if(n==0)
		return 0;
	if(n<0)
		n=-n;
	if(n%2==0)
		return 4*square(floor(n/2));
	else
		return 4*square(floor(n/2))+4*floor(n/2)+1;
}



int main()
{
	int n;
	cin>>n;
	cout<<square(n)<<endl;
	return 0;
}