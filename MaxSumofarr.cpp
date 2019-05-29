/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-18 22:07:46 
 * @Description : find the max sum of array 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-20 23:34:54
 */
#include<iostream>
using namespace std;

long MAX(long a,long b,long c)
{
    if(a < b) a = b;
    if(a > c) return a;
    else
    {
        return c;
    }
}

long MaxSub(int arr[],int low,int high)
{
    int i;
    int j;
    long maxLeftSum,maxRightSum;
    long maxLeftBroderSum,leftBroderSum;
    long maxRightBroderSum,rightBroderSum;
    if(low == high)
    {
        if(arr[low] > 0) return arr[low];
        else
        {
            return 0;
        }
    }
    int mid  = (low + high)  / 2;
    maxLeftSum  = MaxSub(arr,low,mid);//count left max sum
    maxRightSum = MaxSub(arr,mid+1,high);//count right max sum
    maxLeftBroderSum = 0;
    leftBroderSum = 0;
    maxRightBroderSum = 0;
    rightBroderSum = 0;
    for(i = mid;i>=low;i--)//mid + left  => maxleftsum
    {
        leftBroderSum += arr[i];
        if(leftBroderSum > maxLeftBroderSum)
        {
            maxLeftBroderSum = leftBroderSum;
        }
    }
    for(j = mid+1;j<high;j++)//mid + right => maxrightsum
    {
        rightBroderSum += arr[j];
        if(rightBroderSum > maxRightBroderSum)
        {
            maxRightBroderSum = rightBroderSum;
        }
    }
    return MAX(maxLeftSum,maxRightSum,maxLeftBroderSum + maxRightBroderSum);
}

long  MaxSum(int n,int arr[])
{
    int sum=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(b>0) b+=arr[i];
        else b=arr[i];
        if(b>sum) sum=b;
    }
    return sum;
}


int main()
{
    int size;
    cout<<"Input the size of array :";
    cin>>size;
    int arr[size];
    for(int i = 0 ;i< size;i++)
    {
        cout<<"Input the "<<i+1<<" elem in array :";
        cin>>arr[i];
    }
    long x = MaxSub(arr,0,size-1);
    cout<<"(Method 1  /nlogn)The max  is "<<x<<endl;

    int y = MaxSum(size,arr);
    cout<<"(Method 2  /n)The max is "<<y<<endl;

    return 0;
}
