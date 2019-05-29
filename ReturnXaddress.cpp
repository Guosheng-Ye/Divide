/*================================================================
*  @FileName: ReturnXaddress.cpp
*  @Author  : YeGuosheng 
*  @CreateTime : 2019-03-23 07:28:49
*  @Description: 
* For single linked list L without lead node, a recursive algorithm is 
designed to return the address of the node with the first value of x
*, returns NULL when no such node exists.
*  @Last Modified time: 2019-03-23 14:56:49
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

int count = 1;
int Find(LinkList *L,int desElem)
{
    if(L == NULL) return -1;
    if(L->data == desElem) return count;
    else
    {
        count++;
        Find(L->next,desElem);
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
    int sizeOfList;
    cout<<"Input the size of List:";
    cin>>sizeOfList;
    LinkList *p;
    CreateList(p,sizeOfList);
    int desElem;
    cout<<"Input the elem you want to find:";
    cin>>desElem;
    int x = Find(p,desElem);
    if(x == -1)cout<<"NULL"<<endl;
    else
    {
        cout<<x<<endl;
    }
    return 0;
}
