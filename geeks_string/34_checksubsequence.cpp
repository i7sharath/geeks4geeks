#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n1=s1.length(),n2=s2.length();
	int index1=0,index2=0;
	while(index1<n1 && index2<n2)
	{
		if(s1[index1]==s2[index2])
		{
			index1++;
			index2++;
		}
		else
			index2++;
	}

	if(index1==n1 && index2==n2)
		cout<<"True"<<endl;
	else if(index1==n1)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;


	return 0;
}