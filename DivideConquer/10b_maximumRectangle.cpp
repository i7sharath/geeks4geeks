#include <bits/stdc++.h>

using namespace std;

 int crossOver(vector<int>& vec,int start,int mid,int end,int low,int middleArea)
  {
    	int l,r;
    	l=mid;
    	r=mid+1;
    	while(l>start || r<end)
    	{
    	    int k;
    		if(l==start)
    			k=++r;
    		else if(r==end)
    			k=--l;
     		else if(vec[l-1]>=vec[r+1])
    			k=--l;
    	    else
    		    k=++r;
    	    low=min(low,vec[k]);
        	middleArea=max(middleArea,(r-l+1)*low);
    	}
    	return middleArea;

  }


int Helper(vector<int>& vec,int start,int end)
{
	if(start>end)
		return 0;
	if(start==end)
		return vec[start];

	int mid=start+(end-start)/2;

	int low=min(vec[mid],vec[mid+1]);
	int middleArea=low*2;
	
	int lh=Helper(vec,start,mid);
	int rh=Helper(vec,mid+1,end);
	int  crossval=crossOver(vec,start,mid,end,low,middleArea);
	return max(lh,max(rh,crossval));
}

int largestRectangleArea(vector<int>& heights) 
{
	int n=heights.size();
    return Helper(heights,0,n-1);  
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	cout<<largestRectangleArea(vec)<<endl;
	return 0;
}