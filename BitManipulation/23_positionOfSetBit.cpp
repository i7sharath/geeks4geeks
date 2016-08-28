#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int positionOfSetBit(int n)
{
  if(n>0 && (n&(n-1)))
      return -1;
  int pos=1;
  while(n>0)
  {
    if(n&1)
        break;
    pos++;
    n=n>>1;
  }

  return pos;
}

int main()
{
  int n;
  cin>>n;
  cout<<positionOfSetBit(n)<<endl;
  return 0;
}