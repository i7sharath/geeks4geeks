#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void interleavingStrings(string str1,string str2,string str3,int index,int ind1,int ind2,int end)
{

	if(index==end)
		cout<<str3<<endl;
	if(ind1<str1.size())
	{
		str3[index]=str1[ind1];
		interleavingStrings(str1,str2,str3,index+1,ind1+1,ind2,end);
	}
	if(ind2<str2.size())
	{
		str3[index]=str2[ind2];
		interleavingStrings(str1,str2,str3,index+1,ind1,ind2+1,end);
	}
}



int main()
{
	string str1,str2;
	getline(cin,str1,'\n');
	getline(cin,str2,'\n');
	string str3=str1+str2;
	int index=0;
	interleavingStrings(str1,str2,str3,index,0,0,str3.size());
}