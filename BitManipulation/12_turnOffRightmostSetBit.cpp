
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

void TurnoffRightmostSetBit(unsigned n)
{
	return (n & n-1);
}

int main()
{
	unsigned n;
	cin>>n;
	TurnoffRightSetlmostBit(n);
	return 0;
}