/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-18 19:56:48 
 * @Description: find the maxnum and the next maxnum
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-18 20:52:04
 */
#include<iostream>
using namespace std;

void Solve(int arr[],int low,int high,int &max1,int & max2)
{
    if(low == high)
    {
        max1 = arr[low];
        max2 = -1111111;
    }
    else if(low == high -1)
    {   
        max1 = max(arr[low],arr[high]);
        max2 = min(arr[low],arr[high]);
    }
    else
    {
        int mid = (low  + high ) / 2;
        int lmax1;
        int lmax2;
        Solve(arr,low,mid,lmax1,lmax2);//left max
        int rmax1;
        int rmax2;
        Solve(arr,mid+1,high,rmax1,rmax2);//right max
        if(lmax1 >  rmax1)
        {
            max1 = lmax1;
            max2 = max(lmax2,rmax1);
        }
        else
        {
            max1 = rmax1;
            max2 = max(lmax1,rmax2);
        }   
    }
}

int main()
{
    int arrSize;
    int max1;
    int max2;
    cout<<"Input the size of array:";
    cin>>arrSize;
    int arr[arrSize];
    for(int i = 0;i<arrSize ;i++)
    {
        cout<<"Input the "<<i+1<<" elem:";
        cin>>arr[i];
    }
    Solve(arr,0,arrSize-1,max1,max2);
    cout<<"The max num is "<<max1<<endl;
    cout<<"The next max num is"<<max2<<endl;
    return 0;
}
