/*************************************************************************
	> File Name: MatchArrange.cpp
	> Author: YeGuoSheng
	> Description: 
    The round-robin schedule
	> Created Time: 2019-03-31  22：06：02：
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 101
int k;
int arr[MAX][MAX];

void Plan(int k)
{
    int i;
    int j;
    int n;
    int t;
    int temp;
    n = 2;
    arr[1][1] = 1;
    arr[1][2] = 2;
    arr[2][1] = 2;
    arr[2][2] = 1;
    for(t = 1;t < k;++t)//Iterate over 2^k players
    {
        temp = n;//temp=2^t
        n = n * 2;//n = 2^（t +1）
        for(i = temp + 1; i <= n;i++)//
        {
            for(j = 1;j <= temp;j++)
            {
                arr[i][j] = arr[i -temp][j] + temp;//Lower left element
            }
        }
    }
    for(i = 1; i <= temp; i++)//Upper right elemen
    {
        for(j = temp +  1; j <= n;j++)
        {
            arr[i][j] = arr[i+temp][(j+temp) % n];
        }
    }
    for(i = temp + 1;i <= n; i++)
    {
        for(j = temp + 1;j <= n;j++)
            {
                arr[i][j] =arr[i - temp][j -temp];
            }
    }
}



int main()
{
   cin>>k;
   int n = 1 << k;
   Plan(k);
   for(int  i = 1 ;i <= n ;++i)
   {
       for(int j = 1;j <=n ;++j)
       {
            printf("%4d",arr[i][j]);
       }
       cout<<endl;
   }
   return 0;
}
