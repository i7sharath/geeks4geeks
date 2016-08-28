#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

unsigned int swapNibbles(unsigned int n)
{
	unsigned int first=(n &0x0F)<<4;
	unsigned int second=(n & 0xF0)>>4;
	return (first | second);
}

int main()
{
	unsigned int n;
	cin>>n;
	cout<<swapNibbles(n)<<endl;
	return 0;
} 