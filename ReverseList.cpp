/*================================================================
*  @FileName: ReverseList.cpp
*  @Author  : YeGuosheng 
*  @CreateTime : 2019-03-23 07:28:26
*  @Description: 
*  For single linked list L without lead node, a recursive algorithm 
is designed to output all node values in reverse order.
*  @Last Modified time: 2019-03-23 14:43:26
================================================================*/
#include<iostream>
using namespace std;
#include<malloc.h>
typedef struct node
{
    /* data */
    int data;
    struct  node *next;
}LinkList;

void CreateList(LinkList *&L,int n)
{
    int x;
    L  = (LinkList*)malloc(sizeof(LinkList));
    LinkList *t;
    t = L;
    cout<<"Input the 1 elem:";
    cin>>x;
    L->data = x;
    L->next = NULL;
    LinkList *p;
    for(int i =  1;i <n;i++)
    {
        cout<<"Input the "<<i+1<<" elem:";
        cin>>x;
        p  = (LinkList*)malloc(sizeof(LinkList));
        p->data = x;
        t->next = p;
        t = p;
    }
    t->next = NULL;
}

void Disp(LinkList *L)
{
    while(L != NULL)
    {
        cout<<L->data<<" ";
        L = L->next;
    }
}

void RevDisp(LinkList *L)
{
    if(L == NULL )return ;
    else
    {
        RevDisp(L->next);
        cout<<L->data<<" ";
    }
}
void Destory(LinkList *&L)
{
    LinkList *pre = L;
    LinkList *p = L->next;
    while( p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

int main()
{
    LinkList *p;
    int n ;
    cin>>n;
    CreateList(p,n);
    Disp(p);
    cout<<endl;
    cout<<"Reverse Disp:";
    RevDisp(p);
    Destory(p);
    return 0;
}

