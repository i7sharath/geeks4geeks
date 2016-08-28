/*
nput: A array arr[] of two elements having value 0 and 1

Output: Make both elements 0.

Specifications: Following are the specifications to follow.
1) It is guaranteed that one element is 0 but we do not know its position.
2) We can’t say about another element it can be 0 or 1.
3) We can only complement array elements, no other operation like and, or, multi, division, …. etc.
4) We can’t use if, else and loop constructs.
5) Obviously, we can’t directly assign 0 to array elements.
*/




#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void arraySetzero(vector<int>& vec)
{
	vec[vec[0]]=vec[vec[1]]
	return ;
}

int main()
{
	vector<int> vec(2);
	vec[0]=1;
	vec[1]=0;
	cout<<arraySetzero(vec)<<endl;
	return 0;
}