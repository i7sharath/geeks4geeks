#include <bits/stdc++.h>

using namespace std;


string zigZag(string A, int B) 
{
    vector<vector<char> > vec(B);
        string ans;
        int pos=0;
        int index=0;
        while(index<A.length())
        {
            if(pos%2==0)
            {
                for(int j=0;j<B && index<A.length();j++)
                {
                    vec[j].push_back(A[index++]);
                }
            }
            else
            {
                for(int j=B-2;j>0 && index<A.length();j--)
                {
                    vec[j].push_back(A[index++]);
                }
            }
            pos++;
        }
        
        for(int i=0;i<B;i++)
        {
            for(int j=0;j<vec[i].size();j++)
             {
                 ans+=vec[i][j];
             }
        }
        return ans;
}





int main()
{
	string s;
	getline(cin,s);
 	int n;
 	cin>>n;
	cout<<zigZag(s,n)<<endl;
	return 0;
}
