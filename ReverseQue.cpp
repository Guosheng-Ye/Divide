/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-25 20:15:00 
 * @Description : (3,1,4,5,2)  i <j && ai > aj => <3,1> <3,2> <4,2> <5,2>
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-25 21:00:59
 */
#include<iostream>
using namespace std;
#include<malloc.h>

int ans = 0 ;

void Merge(int arr[],int low,int mid,int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int *temp = (int *)malloc((high-low+1) * sizeof(int));
    while(i <= mid && j <= high)
    {
        if(arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
            ans += mid -i +1;
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }
    while(i<= mid) temp[k++] = arr[i++];
    while(j <= high) temp[k++] = arr[j++];
    for(int k1 = 0;k1 < k;k1++)
    {
        arr[low + k1] = temp[k1];
    }
    free(temp);

}

void MergeSort(int arr[],int low,int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid +1,high);
        Merge(arr,low,mid,high);
    }
}

void Inversion(int arr[],int n)
{
    ans = 0;
    MergeSort(arr,0,n-1);
}

int main()
{
    int sizeOfArray;
    cout<<"Input the size of array:";
    cin>>sizeOfArray;
    int arr[sizeOfArray];
    cout<<"Input the elem in array"<<endl;
    for(int i = 0;i<sizeOfArray; i++)
    {
        cin>>arr[i];
    }
    Inversion(arr,sizeOfArray);
    cout<<"ans :"<<ans<<endl;
    return 0;
}
