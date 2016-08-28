#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void MultiplyBy7(unsigned int n)
{
	n=((n<<3)-n);
	cout<<n<<endl;
	return;
}

int main()
{
	unsigned int n;
	cin>>n;
	MultiplyBy7(n);
	return 0;
}