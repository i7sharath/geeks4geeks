#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

void binaryRepresentation(unsigned int n)
{

   unsigned int i=1<<31;
   while(i>0)
   {
        if(n&i)
            cout<<"1";
        else
            cout<<"0";
        i=i>>1;
   }
   return ;
}

int main()
{
    int n;
    cin>>n;
    binaryRepresentation(n);
    return 0;
}