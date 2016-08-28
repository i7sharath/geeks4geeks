#include <iostream>
using namespace std;

 int checkBleak(int n)
 {
 	for(int i=1;i<n;i++)
 	{
 		if(i+__builtin_popcount(i)==n)
 			return 0;
 	}
 	return 1;
 }
 
 
int main()
{
   int n;
   cin>>n;
   int flag=checkBleak(n);
   if(flag)
   		cout<<"True"<<endl;
   else
   		cout<<"False"<<endl;
   return 0;
}


