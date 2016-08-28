#include <bits/stdc++.h>

using namespace std;

void MaxMinformArray(vector<int>& vec,int n)
{
    int temp,i,j;
    for(i=0;i<n;i++)
    {
        temp=vec[i];
        while(temp > 0)
        {
            if(i<n/2)
                j=2*i+1;
            else
                j=2*(n-i-1);

            if(i==j)
            {
                vec[i]=-temp;
                break;
            }
            swap(temp,vec[j]);
            vec[i]=-vec[i];
            i=j;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(vec[i]<0)
            vec[i]=-vec[i];
    }
   return;
}


int main()
{
    int testcases;
    cin>>testcases;
    for(int t=0;t<testcases;t++)
    {
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];
        MaxMinformArray(vec,n);
        for(int i=0;i<n;i++)
            cout<<vec[i]<<" ";
        cout<<endl;
    }
    return 0;
}