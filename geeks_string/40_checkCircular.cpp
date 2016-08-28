#include <bits/stdc++.h>

using namespace std;

bool checkCircular(string s,int n)
{
	int x=0,y=0;
	int dir=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')
		{
			dir=(dir-1)%4;
			if(dir<0)
				dir+=4;
		}
		else if(s[i]=='R')
			dir=(dir+1)%4;
		else 
		{
			if(dir==0)
			y++;
			else if(dir==1)
				x++;
			else if(dir==2)
				y--;
			else if(dir==3)
				x--;	
		}
		
	}
	if(x==0 && y==0)
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
		string s;
		cin>>s;
		bool flag=checkCircular(s,s.length());
		if(flag)
			cout<<"Circular"<<endl;
		else
			cout<<"Not Circular"<<endl;
		testcases--;
	}
	return 0;
}