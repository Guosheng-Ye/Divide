/*************************************************************************
	> File Name: FindElemCloseX.cpp
	> Author: YeGuoSheng
	> Description:Finds the element closest to a given value x in a nonhealth sequence
	> Created Time: 2019-04-01  22:11:50
 ************************************************************************/

#include<iostream>
#include<set>
#include<cmath>
using namespace std;
#define MAXN 100000
int n;
int m;
int arr[MAXN];

int ans ;
int front;
int rear;
set<int >s1;

int Find(set<int>&s2,int x)
{
	if(s2.find(x) == s2.end())
	{
		s2.insert(x);
		set <int> ::iterator it;
		it = s2.find(x);
		if(x < front)
		{
			return front;
		}
		else if(x > rear)
		{
			return rear;
		}
		else
		{
			int ldec =  x - *(--it);
			int rdec = *(++(++it)) - x;//find the difference between right and left
			if(rdec < ldec)
			{
				return  *it;
			}
			else
			{
				return *----it; 
			}
		}
	}
	else 
	{
		return x;
	}
}

int main()
{	
	int i;
	int x;
	cin>>n;

	cin>>x;
	front = x;
	s1.insert(x);

	for( i= 0; i < n-2; i ++)
	{
		cin>>x;
		s1.insert(x);
	}
	cin>>x;
	rear = x;
	s1.insert(x);

	set<int >s2;
	cin>>m;
	for( i = 0; i < m ;i++)
	{
		s2 = s1;
		cin>>x;
		ans = Find(s2,x);
		cout<<ans<<endl;
	}
	return 0;
}
/*
#include<iostream>
using namespace std;
#define N 10000
#define abs(x) ( (x) > 0 ? (x) : -(x) )
int arr[N];

int BinSearch(int low,int high,int x)
{
	int mid;
	while(low < high)
	{
		mid = (low + high) / 2;
		if(arr[mid] > x)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
		if(low + 1 == high)
		{
			if(abs(x - arr[low])  > abs(x - arr[high]))
			{
				low = high;
			}
			else
			{
				high = low;
			}
		}
	}
	return low;
}
int main()
{
	int n;
	int m;
	int x;
	int i;
	for(i = 0; i < n;i++)
	{
		cin>>arr[i];
	}
	cin>>m;
	while( m-- )
	{
		cin>>x;
		int t  =BinSearch(0,n-1,x);
		cout<<t<<endl;
	}
	return 0;
}
*/
