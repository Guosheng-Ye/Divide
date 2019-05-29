/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-20 22:09:07 
 * @Description : find the false coin
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-20 22:58:09
 */
#include<iostream>
#include<time.h>
using namespace std;
#define MAX 100
int arr[MAX] ;

int Sum(int low,int high)
{
    int sum = 0;
    for(int i = low;i<=high;i++)
    {
        sum += arr[i];
    }
    return sum;
}

int FindFalseCoin(int low,int high)
{
    if(low == high) return low;
    if(low == high - 1) 
    {
        cout<<"Coin "<<low<<" ~ "<<low<<" and "<<high<<" ~ "<<high <<" weigh once ";
        if(arr[low] < arr[high])
        {
            cout<<"left's weigh less than right"<<endl;
            return low;
        }
        else
        {
            cout<<"right's weigh less than left"<<endl;
            return high;
        }
    }
    int mid  = (low + high) / 2;
    int sum1;
    int sum2;
    if((high - low +1) % 2 == 0)
    {
        sum1 = Sum(low,mid);
        sum2 = Sum(mid+1,high);
        cout<<"Coin "<<low<<" ~ "<<mid<<" and "<<mid+1<<" ~ "<<high <<" weigh once ";
    } 
    else
    {
        sum1 = Sum(low,mid - 1);
        sum2 = Sum(mid+1,high); 
        cout<<"Coin "<<low<<" ~ "<<mid-1<<" and "<<mid+1<<" ~ "<<high <<" weigh once ";
    }
    if(sum1 == sum2)
    {
        cout<<"Equal Weigh ";
        return mid;
    }
    else if(sum1 < sum2)
    {
        cout<<" left's weigh less than right "<<endl;
        if((high-low+1) % 2 == 0)
        {
            return FindFalseCoin(low,mid);
        }
        else
        {
            return FindFalseCoin(low,mid-1);
        }
    }
    else
    {
        cout<<" right's weight less than left "<<endl;
        return FindFalseCoin(mid+1,high);
    }
}

int main()
{       
    /*
        true coin :2;
        false coin : 1
    */
    int sizeOfCoin;
    cout<<"Input the size of coin:";
    cin>>sizeOfCoin;
    srand((unsigned)time(NULL));
    for(int i = 0 ;i < sizeOfCoin ;i++)
    {
        arr[i] = 2;
    }
    arr[rand() % sizeOfCoin] = 1;
    
    int falseCoin = FindFalseCoin(0,sizeOfCoin-1);
    cout<<"false coin "<<falseCoin<<endl;
    cout<<"Coin Array:";
    for(int i = 0 ;i < sizeOfCoin ;i++)
    {
        cout<<arr[i]<<" "; 
    }
    return 0;
}
