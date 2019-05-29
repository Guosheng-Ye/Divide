/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-18 20:52:34  
 * @Description : bin search 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-18 21:06:06
 */
#include<iostream>
using namespace std;

int BinSearch(int arr[],int low,int high,int k)
{

    int mid ;
    if(low < high )
    {
        mid = (low + high) / 2;
        if(arr[mid] == k)
        {
            return mid;
        }
        if(arr[mid] > k)
        {
            return BinSearch(arr,low,mid-1,k);
        }
        if(arr[mid] < k)
        {
            return BinSearch(arr,mid + 1,high,k);
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    int arrSize;
    cout<<"Input the size of array:";
    cin>>arrSize;
    int arr[arrSize];
    for(int i  = 0 ;i< arrSize ;i++)
    {
        cout<<"Input the "<<i+1<<" elem in array ";
        cin>>arr[i];
    }
    int k ;
    cout<<"Input the num you search :";
    cin>>k;
    int j = BinSearch(arr,0,arrSize-1,k);
    if(j < 0)
    {
        cout<<"Can't find the "<<k<<" in array "<<endl;
    }
    else
    {
        cout<<"arr["<<j<<"] == "<<k<<endl;
    }

    return 0;
}