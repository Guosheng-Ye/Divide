/*************************************************************************
	> File Name:Ai-Aj=C.cpp
	> Author: YeGuoSheng
	> Description: for n numbers and a interger c，how many i and j fulfil( Ai-Aj = C)
	> Created Time: 2019-04-01  20：00：41
 ************************************************************************/

#include<iostream>
using namespace std;
#include <set>
#include<vector>

int ans = 0;

int Solve(multiset<int> &s1,int C)
{
	multiset <int>::iterator it;
	multiset <int>::iterator it2;
	multiset <int>::iterator it3;
	for(it = s1.begin(); it != s1.end(); ++it)
	{
		int t = C + *it;
		it2 = it;
		for(it3 = it2++; it3 != s1.end();++it3)
		{
			if(t == *it3)
			{
				ans++;
			}
		}
	}
	return ans;
}

int main()
{
	int N;
	int C;
	cin>>N>>C;
	multiset<int> s1;
	int x;
	//multiset <int>::iterator it;
	for(int i = 0;i < N ;++i)
	{
		cin>>x;
		s1.insert(x);
	}
	cout<<Solve(s1,C);
	return 0;
}
/*
coutn arr[j]+c appear's num 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 200000

int arr[MAX];
int n;
int c;

int BinSearch(int low,int high,int x)//find x num
{
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(arr[mid] == x)
		{
			int count = 1;
			int i;
			i = mid - 1;
			while(i >= low && arr[i] == x)//find x in the left of arr[mid]
			{
				count++;
				i --;
			}
			i = mid + 1;
			while(i <= high && arr[i] == x)//find x in the right of arr[mid]
			{
				count++;
				i++;
			}
			return count;
		}
		else if(x > arr[mid])
		{
			low = mid +1;//x > arr[mid]
		}
		else
		{
			high = mid -1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&c);
	for(int i = 0; i < n ;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int ans  = 0;
	for(int j = 0; j < n - 1;j++)
	{
		ans += BinSearch(j+1, n-1,arr[j] + c);
	}
	cout<<ans<<endl;
	return 0;
}
