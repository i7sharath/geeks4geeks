#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

unsigned int swapEvenOddBits(unsigned int n)
{
	unsigned int evenbits= n & 0xAAAAAAAA;
	unsigned int oddbits= n &  0x55555555;
	evenbits>>=1;
	oddbits<<=1;
	return (evenbits | oddbits);
}

int main()
{
	unsigned int n;
	cin>>n;
	cout<<swapEvenOddBits(n)<<endl;
	return 0;
} 