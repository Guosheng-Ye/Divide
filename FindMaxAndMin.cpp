/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-25 21:30:31 
 * @Description : find the maxnum and minnum in array by divide 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-25 21:45:07
 */
#include<iostream>
#include<stdio.h>
using namespace std;
#include<algorithm>
#define max(x,y) ( (x) > (y) ? (x):(y) )
#define min(x,y) ( (x) < (y) ? (x):(y) )

void Solve(int arr[],int low,int high,int &maxelem,int &minelem)
{
    if(low == high)
    {
        maxelem = arr[low];
        minelem = arr[low];
    }
    else if(low +1 == high)
    {
        maxelem = max(arr[low],arr[high]);
        minelem = min(arr[low],arr[high]);
    }
    else
    {
        int mid = (high + low) / 2;
        int leftmax;
        int leftmin;
        Solve(arr,low,mid,leftmax,leftmin);
        int rightmax;
        int rightmin;
        Solve(arr,mid+1,high,rightmax,rightmin);
        maxelem = max(leftmax,rightmax);
        minelem = min(leftmin,rightmin);
    }
   
}

int main()
{
    int sizeOfArray;
    cout<<"Input the size of array :";
    cin>>sizeOfArray;
    int arr[sizeOfArray];
    for(int i = 0;i < sizeOfArray;i++)
    {
        cin>>arr[i];
    }
    int max;
    int min;
    Solve(arr,0,sizeOfArray-1,max,min);
    cout<<"Max: "<<max<<" Min "<<min<<endl;
    return 0;
}
