/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-25 21:46:58 
 * @Description: Pow(x,n) by divide  
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-25 22:08:12
 */
#include<iostream>
using namespace std;

int Solve(int x,int n)
{
    double ans;
    if(n == 1)
    {
        return x;
    }
    if(n  % 2 == 0)
    {
        ans =  Solve(x,n/2) ;
        return ans * ans;
    }
    else
    {
        ans = Solve(x,(n-1) /2);
        
        return ans * ans * x;
    }
    
}

int main()
{  
    int x;
    int n;
    cout<<"Input the x and  n"<<endl;
    cin>>x>>n;
    cout<<Solve(x,n);
    cout<<endl;
    return 0;
}
