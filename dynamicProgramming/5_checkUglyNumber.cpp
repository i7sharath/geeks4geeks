#include <bits/stdc++.h>

using namespace std;


bool isUgly(int num) 
{
    if(num<=0)
        return false;
    if(num==1)
        return true;
    while(num>1)
    {
        if(num%2==0)
            num/=2;
        else
            break;
    }
    while(num>1)
    {
        if(num%3==0)
            num/=3;
        else
            break;
    }
    while(num>1)
    {
        if(num%5==0)
            num/=5;
        else
            break;
    }
    if(num==1)
        return true;
    else
        return false;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		bool flag=isUgly(n);
		cout<<flag<<endl;
		testcases--;
	}

	return 0;
}