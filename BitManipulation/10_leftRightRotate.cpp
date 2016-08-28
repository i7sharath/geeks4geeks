#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int leftrotate(int n,int d)
{
	return (n << d) | (n >> ((sizeof(n)*8)-d));
}

int rightrotate(int n,int d)
{
	return (n >> d) | (n << ((sizeof(n)*8)-d));
} 

int main()
{
	int n,d;
	cin>>n>>d;
	int num1=leftrotate(n,d);
	cout<<"after leftrotate"<<num1<<endl;
	int num2=rightrotate(n,d);
	cout<<"after rightrotate"<<num2<<endl;
	return 0;
}