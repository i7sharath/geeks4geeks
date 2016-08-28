#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>

using namespace std;

void PrintListItems(vector<string> list,string word)
{
	
	for(int i=0;i<list.size();i++)
	{
		map<char,int> m;
		map<char,int>:: iterator it;
		for(int j=0;j<list[i].size();j++)
		{
			it=m.find(list[i][j]);
			if(it==m.end())
				m.insert(pair<char,int>(list[i][j],1));
			else
				it->second+=1;
		}
		int flag=0;
		for(int k=0;k<word.length();k++)
		{
			it=m.find(word[k]);
			if(it==m.end())
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<list[i]<<endl;
		m.clear();

	}
	
	
	return;
}

int main()
{
	vector<string> list;
	list.push_back("geeksforgeeks");
	list.push_back("unsorted");
	list.push_back("sunday");
	list.push_back("just");
	list.push_back("sss");
	string word="sun";
	PrintListItems(list,word);
	return 0;
}