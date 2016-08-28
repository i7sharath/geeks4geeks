#include <bits/stdc++.h>

using namespace std;

void printPath(string s,int n)
{
	int index=0;
	int curX=0,curY=0;
	while(index<n)
	{
		int nextX = (s[index]-'A')/5; 
		int nextY = (s[index]-'A')%5;
		while(curX > nextX)
		{
			cout<<"Move Up"<<endl;
			curX--;
		}

		while(curY > nextY)
		{
			cout<<"Move Left"<<endl;
			curY--;
		}

		while(curX < nextX)
		{
			cout<<"Move Down"<<endl;
			curX++;
		}

		while(curY < nextY)
		{
			cout<<"Move Right"<<endl;
			curY++;
		}

		cout<<"Press Ok"<<endl;
		index++;
	}
	return;
}

int  main()
{
	string s;
	cin>>s;
	printPath(s,s.length());
	return 0;	
}