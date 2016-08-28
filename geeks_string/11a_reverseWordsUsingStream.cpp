#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

void reverseWords(string &s) 
{
    vector<string> str;
    stringstream ss(s);
    string word;
   
    while(ss>>word)
    {
        str.push_back(word);
    }

    for(int i = str.size() - 2; i>=0; i--)
    {
        word+=" ";
        word+=str[i];
     }
    s = word;
    cout<<s<<endl;
    return;
}

int main()
{
	string s;
	getline(cin,s,'\n');
	reverseWords(s);

	return 0;
}