#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int main()
{
    unsigned int x = 1<<15 + 1<<16;
    cout<<sizeof(x)<<endl;
    // cout << isPalindrome(x) << endl;
    // x = 1<<31 + 1;
    // cout << isPalindrome(x) << endl;
    return 0;
}