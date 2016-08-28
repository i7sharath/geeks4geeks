#include <bits/stdc++.h>

using namespace std;

void generateBrackets(int n,vector<string>& ans,string out,int open,int close)
{
    if(close==n)
    {
        ans.push_back(out);
        return;
    }
    else
    {
        if(open>close)
        {
          string temp=out;
          temp.push_back(')');
          generateBrackets(n,ans,temp,open,close+1);
        }

        if(open<n)
        {
          string temp=out;
          temp.push_back('(');
          generateBrackets(n,ans,temp,open+1,close);
        }
    }
    return;
}

int main()
{
  int n;
  cin>>n;
  vector<string> ans;
  if(n==0)
    return 0;
  string out;
  generateBrackets(n,ans,out,0,0);
  reverse(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}