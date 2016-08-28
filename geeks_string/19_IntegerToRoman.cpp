#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	cin>>num;
	map<int,string> m;
	map<int,string> :: reverse_iterator rit;
	string ans;
	m[1]="I";
	m[4]="IV";
	m[5]="V";
	m[9]="IX";
	m[10]="X";
	m[40]="XL";
	m[50]="L";
	m[90]="XC";
	m[100]="C";
	m[400]="CD";
	m[500]="D";
	m[900]="CM";
	m[1000]="M";

	for(rit=m.rbegin();num!=0;rit++)
	{
		while(num>=rit->first)
		{
			num-=(rit->first);
			ans+=(rit->second);
		}
	}
	cout<<ans<<endl;
	return 0;

}