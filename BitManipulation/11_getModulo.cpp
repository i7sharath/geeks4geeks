//Compute n modulo d without division(/) and modulo(%) operators, where d is a power of 2 number. 


#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

int getModulo(unsigned n,unsigned int d)
{
	return (n & (d-1));
	
}

int main()
{
	unsigned n,d;
	cin>>n>>d;
	int num=getModulo(n,d);
	cout<<num<<endl;
	return 0;
}