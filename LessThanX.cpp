/*************************************************************************
	> File Name:LessThanX.cpp
	> Author: YeGuoSheng
	> Description: Given a whole sequence of monotonically increasing Numbers of length n, with m queries, 
	one x at a time, what is the last number in the sequence less than or equal to x
	>             1 <= n, m <= 1000000 
	> Created Time: 2019-04-010  21：25：06
 ************************************************************************/

#include<iostream>
using namespace std;
#include<set>
int start;

void Find(set <int> &s1,int x,int &ans)
{
	ans = 0;
	int elem;
	if(x < start)
	{
		ans = -1;
		return ;
	}
	if(s1.find(x) != s1.end())//Find the direct return element
	{
		ans = *s1.find(x);
		return ;
	}
	else
	{
		Find(s1,x-1,ans);
		return;
	}
	
}

int main()
{
	int n;
	int m;
	int x;
	int ans = 0;
	cin>>n>>m;
	set <int> s1;
	set <int>::iterator it;

	cin>>x;
	s1.insert(x);//start elem
	start  = x;

	for(int i = 0;i < n-1 ;i++)//n-1 elem
	{
		cin>>x;
		s1.insert(x);
	}

	for(int j = 0; j <m;j++)
	{
		ans = 0;
		int y;
		cin>>y;
		Find(s1,y,ans);
		cout<<ans<<endl;
		
	}
	return 0;
}
/*Description:  Binary search x, when x==arr[mid], successful search, return arr[mid], 
if not found at the end of the loop,
Arr [high] is the last element less than or equal to x. If high<0, it does not exist
#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 1000000
int arr[MAXN];
int n;
int m;

int BinSearch(int low,int high,int x)
{
	int mid ;
	while(low <= high)
	{
		mid = (low + high ) / 2;
		if(arr[mid] == x)
		{
			return arr[mid];
		}
		else if(arr[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	if(high < 0)
	{
		return -1;
	}
	else
	{
		return arr[high];
	}
	
}

int main()
{
	int x;
	int i;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i = 0 ;i < n ;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(i = 0; i < m ;i++)
		{
			scanf("%d",&x);
			cout<<BinSearch(0,n-1,x)<<endl;
		}
	}
	return 0;
}
*/


