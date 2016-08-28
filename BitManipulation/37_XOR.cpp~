#include <bits/stdc++.h>

using namespace std;

int XOR(int x,int y)
{
	int result=0;
	int xor_bit;
	for(int i=31;i>=0;i--)
	{
		if((x&(1<<i))!=(y &(1<<i)))
			xor_bit=1;
		else
			xor_bit=0;
			
		result=result<<1;
		result=result|xor_bit;
	}
	return result;
}

int main()
{
	int x,y;
	cin>>x>>y;
	cout<<XOR(x,y)<<endl;
	return 0;
}

