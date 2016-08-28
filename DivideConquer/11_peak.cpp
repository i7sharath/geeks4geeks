#include <bits/stdc++.h>

using namespace std;

int Peak(vector<int> &vec,int start,int end)
{
    if(start==end)
        return start;
        
	int mid=start+(end-start)/2;

    if(mid==start && vec[mid+1]<vec[mid])
        return mid;
  
    else if(vec[mid]>vec[mid-1] && vec[mid]>vec[mid+1])
        return mid;
        
    else if (mid>start && vec[mid-1] > vec[mid] )
        return Peak(vec,start,mid -1);
    else 
        return Peak(vec,mid + 1,end);

}
    
int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>vec[i];
	}
	cout<<Peak(vec,0,n-1)<<endl;
	return 0;
}