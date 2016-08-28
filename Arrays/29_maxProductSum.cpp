#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int maxProductSubarray(vector<int>& vec)
{
   int n=vec.size();
   int maxprod=1,currprod=1;
   int i=0,j=0;
   int count=0;
   while(j<n)
   {
   		if(vec[j]==0)
   		{
   			if(count%2==0)
   			{
   				count=0;
   				i=j+1;
   				currprod=1;
   				j++;
   			}
   			else
   			{
   				for(int k=i;k<j;k++)
   				{
   					if(vec[k]<0)
   					{
   						currprod/=vec[k];
   						maxprod=max(maxprod,currprod);
   						currprod=1;
   						count=0;
   						j++;
   						i=j;
   						break;
   					}
   					currprod/=vec[k];
   					k++;
   				}
   			}
   		}
   		else
   		{

   			if(vec[j]<0)
   				count++;
   			currprod*=vec[j];
   			maxprod=max(maxprod,currprod);
   			j++;
   			
   		}
   }
   if(count%2!=0)
   {
   		for(int k=i;k<j;k++)
   		{
   			if(vec[k]<0)
   			{
   				currprod/=vec[k];
   				maxprod=max(maxprod,currprod);
   				break;
   			}
   			currprod/=vec[k];
   		}
   }

   return maxprod;

}



int main() {
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
	    int n;
	    cin>>n;
	    vector<int> vec(n);
	    for(int i=0;i<n;i++)
	        cin>>vec[i];
	    cout<<maxProductSubarray(vec)<<endl;
	}
	return 0;
}