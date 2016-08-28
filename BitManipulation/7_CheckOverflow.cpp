#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void checkOverflow(int a,int b)
{
	int result=a+b;
	if((a>0 && b>0 && result<0)||(a<0 && b<0 && result>0))
		cout<<"Overflow"<<endl;
	cout<<result<<endl;
	return;
}

int main()
{
	int a,b;
	cin>>a>>b;
	checkOverflow(a,b);
	return 0;
}