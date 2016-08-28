#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int smallestOfThree(int x,int y,int z)
{
	int num=y ^ ((x^y) & -(x<y));
    return z ^ ((num ^z) & -(num<z));
  
}


int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	cout<<smallestOfThree(x,y,z)<<endl;
	return 0;
}