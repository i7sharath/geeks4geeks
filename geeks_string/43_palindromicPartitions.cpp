#include<bits/stdc++.h>

using namespace std;


bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
	
void palindromicPartitions(string s,vector<vector<string> >& Allpartitions,vector<string>& currpartitions,int start,int n)
{
	if(start>=n)
	{
		Allpartitions.push_back(currpartitions);
		return ;
	}
	for(int i=start;i<n;i++)
	{
		if(isPalindrome(s,start,i))
		{
			currpartitions.push_back(s.substr(start,i-start+1));
			palindromicPartitions(s,Allpartitions,currpartitions,i+1,n);
			currpartitions.pop_back();
		}
	}
}

int main()
{
	string s;
	cin>>s;
	int n=s.length();
	vector<vector<string> > Allpartitions;
	vector<string> currpartitions;
	palindromicPartitions(s,Allpartitions,currpartitions,0,n);
	for(int i=0;i<Allpartitions.size();i++)
	{
		for(int j=0;j<Allpartitions[i].size();j++)
			cout<<Allpartitions[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}