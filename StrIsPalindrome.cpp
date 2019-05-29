/*================================================================
*  @FileName: StrIsPalindrome.cpp
*  @Author  : YeGuosheng 
*  @CreateTime : 2019-03-23 07:27:42
*  @Description: 
*  For a string STR stored in an array of characters,
a recursive algorithm is designed to determine whether STR is palinese.
*  @Last Modified time: 2019-03-23 08:19:42
================================================================*/
#include<iostream>
using namespace std;
#include<string.h>

bool IsPalindrome(string str,int n)
{
    if(n == 0 || n == 1)return true;
    if( str[0] != str[n-1])return false;
    else
    {
        str.erase(0,1);
        str.erase(n-1,1);
        return IsPalindrome(str,n-2);
    }
}

int main()
{
    string str;
    string str2;
    cin>>str;
    str2 = str;
    int n = str.length();
    if(IsPalindrome(str2,n))
    {
        cout<<str<<" is Palindrome str"<<endl;
    }
    else
    {
        cout<<str<<" is not a Palindrome str"<<endl;
    }
}
