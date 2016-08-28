#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

bool checkMultipleOf9(int n)
{
	if(n==0 || n==9)
		return true;
	if(n<9)
		return false;
	// If n is greater than 9, then recur for [floor(n/9) - n%8]
	return checkMultipleOf9((int)(n>>3) - (int)(n&7));
}

int main()
{
	int n;
	cin>>n;
	cout<<checkMultipleOf9(n)<<endl;
	return 0;
}