#include <bits/stdc++.h>

using namespace std;

void MaxMinformArray(vector<int>& vec)
{
    int n=vec.size();
    vector<int> temp(n);
    for(int i=0;i<n;i++)
        temp[i]=vec[i];

    int index=n-1;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            vec[i]=temp[index];
            index--;
        }   
    }
    if(n%2==0)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(i%2==1)
            {
                vec[i]=temp[index];
                index--;
            }
        }
    }
    else
    {
        for(int i=n-2;i>=0;i--)
        {
            if(i%2==1)
            {
                vec[i]=temp[index];
                index--;
            }
        }
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
        MaxMinformArray(vec);
        for(int i=0;i<n;i++)
            cout<<vec[i]<<" ";
        cout<<endl;
    }
    return 0;
}