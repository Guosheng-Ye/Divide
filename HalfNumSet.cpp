/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-25 21:03:20 
 * @Description : => set(6)  : {6,16,26,126,36,136}
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-25 21:19:38
 */
#include<iostream>
using namespace std;

/*
     set (1) =  {1}       =1
     set {2} = {1,12} = 1 + f(1)   = 2
     set {3} = {1,3}  = 1 + f(1)    = 2
     set {4} = {4,14,24,124,} = 1 + f(1) + f(2) = 4
     set {5} = {5,25,125,} = 1 +f(1) + f(2) = 4
     set {6} = {6,36,136,26,126,16} = 1+ f(1) +f(2) + f(3) = 6
     set {7} = {7,37,137,27,127,17} =  1 + f(1) + f(2) + f(3) = 6;
     set {8}  + {8,18,128,1248,28,248,38,48,138,148} = 1 +f(1) + f(2) + f(3)  + f(4)
*/
int Solve(int n)
{
    int ans = 1;
    if(n > 1)
    {
        for(int i = 1;i<=n/2;i++)
        {
            ans += Solve(i);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<Solve(n);
    return 0;
}
