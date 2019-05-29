/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-21 20:51:31 
 * @Description: find thr aray 's public and it's count 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-21 21:28:31
 */
#include<iostream>
using namespace std;
#include<algorithm>

int  num;
int maxcount = 0;

void Split(int arr[],int low,int high,int &mid,int &left,int &right)
{
    mid  = (low + high) / 2;
    for(left = low;left <= high ;left++)
    {
        if(arr[left] == arr[mid])
        {
            break;
        }
    }
    for(right = left+1;right <= high;right++)
    {
        if(arr[right] != arr[mid])
        {
            break;
        }
    }
    right --;
}

void Solve(int arr[],int low,int high)
{
    if(low <=  high)
    {
        int mid,left,right;
        Split(arr,low,high,mid,left,right);
        int cnt = right - left +1;
        if(cnt > maxcount)
        {
            num = arr[mid];
            maxcount = cnt;
        }
        Solve(arr,low,left-1);
        Solve(arr,right+1,high);
    }
}

int main()
{
    int sizeOfArray;
    cout<<"Input the size of array :";
    cin>>sizeOfArray;
    int arr[sizeOfArray];
    for(int i =0;i<sizeOfArray;i++)
    {
        cout<<"Input the "<< i+1 <<" elem ";
        cin>>arr[i];
    }
    sort(arr,arr+sizeOfArray);
    Solve(arr,0,sizeOfArray-1);
    cout<<"Public num :"<<num<<"  count : "<<maxcount<<endl;
    return 0;
}
