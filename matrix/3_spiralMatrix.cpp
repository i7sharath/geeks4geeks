#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int testcases;
	cin>>testcases;
	while(testcases)
	{
	    vector<vector<int> > vec(4,vector<int>(4,0));
	    for(int i=0;i<4;i++)
	        for(int j=0;j<4;j++)
	            cin>>vec[i][j];
	    int direction=0;
	    int i,j;
	    int left=0,right=3,top=0,bottom=3;
	    while(left<=right && top<=bottom)
	    {
	        if(direction==0)
	        {
	           for(int k=left;k<=right;k++)
	                cout<<vec[top][k]<<" ";
	           top++;
	           direction=1; 
	        }
	        
	        else if(direction==1)
	        {
	            for(int k=top;k<=bottom;k++)
	                cout<<vec[k][right]<<" ";
	            right--;
	            direction=2;
	        }
	        else if(direction==2)
	        {
	            for(int k=right;k>=left;k--)
	                cout<<vec[bottom][k]<<" ";
	            bottom--;
	            direction=3;
	        }
	        else
	        {
	            for(int k=bottom;k>=top;k--)
	                cout<<vec[k][left]<<" ";
	            left++;
	            direction=0;
	        }
	    }
	    cout<<endl;
	    testcases--;
	}
	return 0;
}