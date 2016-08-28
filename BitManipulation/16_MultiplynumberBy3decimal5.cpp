#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int MultiplyBy3decimal5(int n)
{
	return (2*n + n + n/2);
}


int main()
{
	int n;
	cin>>n;
	cout<<MultiplyBy3decimal5(n)<<endl;
	return 0;
}