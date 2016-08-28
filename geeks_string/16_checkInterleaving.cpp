#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool checkInterleavings(string str1,string str2,string str3,int index,int ind1,int ind2,int end)
{
	while(index<end)
	{
		if(str1[ind1]==str3[index])
			ind1++;
		else if(str3[index]==str2[ind2])
			ind2++;
		else
			return false;
		index++;
	}
	if(ind1==str1.size() && ind2==str2.size())
		return true;
	return false;
}


int main()
{
	string str1,str2,str3;
	cin>>str1>>str2>>str3;
	int size=str1.size()+str2.size();
	if(str3.size()!=size)
	{
		cout<<"Not a interleaving"<<endl;
		return 0;
	}

	bool flag=checkInterleavings(str1,str2,str3,0,0,0,str3.size());
	if(flag==true)
		cout<<"interleaving"<<endl;
	else
		cout<<"not interleaving"<<endl;
	return 0;
}