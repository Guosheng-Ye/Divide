/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-18 19:14:19 
 * @Description: quick sort by divide 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-18 19:30:36
 */

#include<iostream>
using namespace std;

void Disp(int arr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
}
int Partition(int arr[],int s,int t)
{
    int i = s;
    int j = t;
    int temp =  arr[s];
    while( i != j)
    {
        while(i < j && arr[j] >= temp)
        {
            j--;
        }
        arr[i] = arr[j];
        while(i < j && arr[i]<=temp)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = temp;
    return i;
}
void QuickSort(int arr[],int s,int t)
{
    if(s < t )
    {
        int i = Partition(arr,s,t);
        QuickSort(arr,s,i-1);//left
        QuickSort(arr,i+1,t);//right
    }
}

int main()
{
    int arraySize;
    cout<<"Please input the size of array :";
    cin>>arraySize;
    int arr[arraySize];
    for(int i = 0;i < arraySize;i++)
    {
        cout<<"Input the "<<i+1<<" elem in arrat ";
        cin>>arr[i];
    }
    cout<<"Before sort:"<<endl;
    Disp(arr,arraySize);
    QuickSort(arr,0,arraySize-1);
    cout<<"After sort:"<<endl;
    Disp(arr,arraySize);

}