#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int testcases;
	cin>>testcases;
	while(testcases)
	{
	    int m,n;
	    cin>>m>>n;
	    vector<vector<int> > vec(m,vector<int>(n,0));
	    for(int i=0;i<m;i++)
	        for(int j=0;j<n;j++)
	            cin>>vec[i][j];
	    int key;
	    cin>>key;
	    int i=m-1,j=0;
	    int flag=0;
	    while(i>=0 && j<n)
	    {
	        if(vec[i][j]==key)
	        {
	            cout<<"1"<<endl;
	            flag=1;
	            break;
	        }
	        else if(key < vec[i][j])
	            i--;
	        else
	            j++;
	    }
	    if(flag==0)
	        cout<<"0"<<endl;
	    testcases--;
	}
	return 0;
}