/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-18 21:08:08 
 * @Description : find the mid num in two array 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-20 23:35:00
 */
#include<iostream>
using namespace std;

void Prepart(int &s,int &t)
{
    int m  = (s + t) /2;
    t = m;
}

void Postpart(int &s,int &t)
{
    int m = (s + t )/2;
    if((s + t) % 2 == 0 )
    {
        s = m;
    }
    else
    {
        s = m + 1;
    }
}

int Midnum(int a[],int s1,int t1,int b[],int s2,int t2)
{
    int m1;
    int m2;
    if(s1 == t1 && s2 == t2)
    {
        return a[s1]<b[s2] ? a[s1]:b[s2];
    }
    else
    {
        m1 = (s1 + t1) / 2;
        m2 = (s2 + t2) / 2;
        if(a[m1] == b[m2])
        {
            return a[m1];
        }
        if( a[m1] < b[m2])// reserve min's postpart  and max 'x prepart
        {   
            Postpart(s1,t1);
            Prepart(s2,t2);
            return Midnum(a,s1,s2,b,s2,t2);
        }
        else
        {
            Postpart(s2,t2);
            Prepart(s1,t1);
            return Midnum(a,s1,t1,b,s2,t2);
        }
    }
}

int main()
{
    int arrSize ;
    cout<<"Input the size of array :";
    cin>>arrSize;
    int a[arrSize];
    int b[arrSize];
    for(int i =0;i < arrSize;i++)
    {
        cout<<"Input the "<<i+1<<" elem in a :";
        cin>>a[i];
    }
    for(int i =0;i < arrSize;i++)
    {
        cout<<"Input the "<<i+1<<" elem in b: ";
        cin>>b[i];
    }
    int midNum = Midnum(a,0,arrSize-1,b,0,arrSize-1);
    cout<<"The midnum is "<<midNum<<endl;
    return 0;
}