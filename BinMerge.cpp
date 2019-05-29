/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-18 19:29:25
 * @Description : bin merge sort 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-18 19:48:29
 */
#include<iostream>
#include<malloc.h>
using namespace std;

void Disp(int arr[],int n)
{
    for(int i =0 ;i < n;i++)
    {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

void Merge(int arr[],int low,int mid,int high)
{
    int *tempa;
    int i = low;
    int j = mid+1;
    int k = 0;//k -> index of tempa 
    tempa = (int *)malloc((high + low + 1) *sizeof(int ));
    while(i <= mid && j<= high)
    {
        if(arr[i] <= arr[j])//put the sub1 in tempa
        {
            tempa[k] = arr[i];
            i++;
            k++;
        }
        else//put the sub2 in tempa
        {
            tempa[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid)//cp  the sub1 last elem  in tempa
    {
        tempa[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high)//cp the sub2 last elem in tempa    
    {
        tempa[k] = arr[j];
        j++;
        k++;
    }
    for(k = 0 ,i = low ;i<=high;k++,i++)//cp the tempa in arr
    {
        arr[i] = tempa[k];
    }
    free(tempa);
}

void MergePass(int arr[],int length,int n)
{
    int i;
    for(i = 0; i +2 * length -1 < n;i = i + 2 * length)
    {
        Merge(arr,i,i+length-1,i+2*length+1);
    }
    if(i + length -1 < n)
    {
        Merge(arr,i,i+length-1,n-1);
    }
}

void MergeSort(int arr[],int n)
{
    int length;
    for(length = 1;length < n;length = 2 * length)
    {
        MergePass(arr,length,n);
    }
}

int main()
{
    int arraySize;
    cout<<"Input the size of array:";
    cin>>arraySize;
    int arr[arraySize];
    for(int i = 0 ; i < arraySize ;i++)
    {
        cout<<"Input the "<<i+1<<" elem in array :";
        cin>>arr[i];
    }
    cout<<"Before sort:"<<endl;
    Disp(arr,arraySize);
    cout<<"After sort:"<<endl;
    MergeSort(arr,arraySize);
    Disp(arr,arraySize);
    return 0;
}
