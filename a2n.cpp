/*================================================================
*  @FileName: a2n.cpp
*  @Author  : YeGuosheng 
*  @CreateTime : 2019-03-23 07:26:58
*  @Description: 
* the first term of the sequence is equal to 0, and the calculation
formula of the subsequent odd and even terms is respectively
A2n = a2n-1 + 2, a2n+1 = a2n-1 + a2n-1, write the recursive algorithm 
for calculating the NTH term of the sequence
*   @Last Modified time: 2019-03-23 07:39:15
================================================================*/
#include<iostream>
using namespace std;
#define MAXSIZE 500
int arr[MAXSIZE] = {0};

int Solve(int n )
{
    if(n == 1)return arr[1];
    if(n % 2 == 0)
        return Solve(n-1) + 2;
    else
    {
        return Solve(n-2) + Solve(n-1) - 1;
    }
}
int main()
{
    int n ;
    cin>>n;
    int ans  = Solve(n);
    cout<<ans<<endl;
    return 0;
}

