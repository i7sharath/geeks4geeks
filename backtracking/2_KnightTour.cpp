#include <bits/stdc++.h>

using namespace std;

void printSolution(vector<vector<int> > &sol)
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
	return;
}
 
bool isValid(vector<vector<int> > &sol,int x,int y)
{
	if(x>=0 && x<8 && y>=0 && y<8 && sol[x][y]==-1)
		return true;
	else
		return false;
}

bool solveHelper(vector<vector<int> >&sol,vector<int> &moveX,vector<int> &moveY,int currmove,int x,int y)
{
	int nextX,nextY;
	if(currmove==64)
		return true;

	for(int i=0;i<8;i++)
	{
		nextX=x+moveX[i];
		nextY=y+moveY[i];
		if(isValid(sol,nextX,nextY))
		{
			sol[nextX][nextY]=currmove;
			if(solveHelper(sol,moveX,moveY,currmove+1,nextX,nextY))
				return true;
			else
				sol[nextX][nextY]=-1;
		}
	}
	return false;
}

void solveKnightTour()
{
	int n=8;
	vector<vector<int> > sol(n,vector<int>(8,-1));

	vector<int> moveX(8);
	moveX={  2, 1, -1, -2, -2, -1,  1,  2 };
	vector<int> moveY(8);
	moveY={  1, 2,  2,  1, -1, -2, -2, -1 };

	sol[0][0]=0;
	if(solveHelper(sol,moveX,moveY,1,0,0)==false)
	{
		cout<<"No Solution Exist"<<endl;
		return;
	}
	else
		printSolution(sol);
	return;
}

int main()
{
	solveKnightTour();
	return 0;
}