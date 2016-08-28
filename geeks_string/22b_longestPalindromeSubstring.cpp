#include <bits/stdc++.h>
using namespace std;

string longestPalindrome1(string s)
{
	int n=s.length();
    int maxlen=1;
    int start;
    int low,high;
    for(int i=1;i<n;i++)
    {
        //palindrome of even length
        low=i-1;
        high=i;
        while(low>=0 && high<n && s[low]==s[high])
        {
            if(high-low+1 > maxlen)
            {
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
        
        //Palindrom of odd length
        low=i-1;
        high=i+1;
        while(low>=0 && high<n && s[low]==s[high])
        {
            if(high-low+1 > maxlen)
            {
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
        
    }

	string ans=s.substr(start,maxlen);
	return ans;

}



int main()
{
	string s;
	getline(cin,s);
	cout<<longestPalindrome1(s)<<endl;
	return 0;
}