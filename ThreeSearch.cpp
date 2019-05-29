/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-26 15:51:26 
 * @Description : three search 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-26 16:08:56
 */
#include<iostream>
using namespace std;

int ThreeSearch(int arr[],int low,int high,int x)
{
    if(high < low )//no elem
    {
        return -2;
    }
    if(high == low)//one elen
    {
        if(arr[low] == x)
        {
            return low;
        }
        else
        {
            return -2;
        }
    }
    if(low +1 == high)
    {
        if(arr[low] ==x )
        {
            return low;
        }
        else if(arr[high] == x)
        {
            return high;
        }
        else
        {
            return -2;
        }
    }
    int length = (high - low +1) / 3;
    int mid1 = low + length;
    int mid2 = high - length;
    if(x == arr[mid1])
    {
        return mid1;
    }
    if(x == arr[mid2])
    {
        return mid2;
    }
    if(x < arr[mid1])
    {
        return ThreeSearch(arr,low,mid1-1,x);
    }
    if(x < arr[mid2])
    {
        return ThreeSearch(arr,mid1,mid2,x);
    }
    else
    {
        return ThreeSearch(arr,mid2,high,x);
    }
    

}

int main()
{
    int sizeOfArray  = 0;
    int x;
    cout<<"Input the size of array :";
    cin>>sizeOfArray;
    int arr[sizeOfArray];
    for(int i = 0; i < sizeOfArray ;i++)
    {
        scanf("%d",&arr[i]);
    }
    cout<<"Input the elem you want to find  :";
    cin>>x;
    cout<<endl;
    cout<<"Location is "<<ThreeSearch(arr,0,sizeOfArray-1,x)+1<<endl;
    return 0;
}
