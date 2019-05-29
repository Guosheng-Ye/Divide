/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-26 14:43:13 
 * @Description : solve the high of btree
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-26 14:44:14
 */
#include<iostream>
using namespace std;

typedef struct node
{
    char data;
    struct node * lchild;
    struct node * rchild;
}BtreeNode;

void CreateBtree(BtreeNode *&b)
{
    b = NULL;
    char ch;
    ch = getchar();
    if(ch == '#')
    {
        b = NULL;
    }
    else
    {
        b = (BtreeNode*)malloc(sizeof(BtreeNode));
        b->data = ch;
        CreateBtree(b->lchild);
        CreateBtree(b->rchild);
    }
}

void Destory(BtreeNode *&b)
{
    if(b != NULL)
    {
        Destory(b->lchild);
        Destory(b->rchild);
        free(b);
    }
}

void PreOrder(BtreeNode *b)
{
    if(b!= NULL)
    {
        cout<<b->data;
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

int Height(BtreeNode *b)
{
    if(b == NULL)
    {
        return 0;
    }
    int lheight = Height(b->lchild);
    int rheight = Height(b->rchild);
    if(lheight > rheight) return lheight +1;
    else return rheight+1;
}

int FindChildIs2(BtreeNode *b)
{
    int ans = 0;
    if(b == NULL)
    {
        return 0;
    }
    if((b->lchild != NULL ) && (b->rchild != NULL))
    {
        ans = 1;
    }
    return FindChildIs2(b->lchild) + FindChildIs2(b->rchild) + ans;
}

int main()
{
    BtreeNode *b;
    CreateBtree(b);
    cout<<"Preorder:";
    PreOrder(b);
    cout<<endl;
    cout<<"Height = "<<Height(b)<<endl;
    cout<<"Find child == 2 :"<<FindChildIs2(b)<<endl;
    Destory(b);
    return 0;
}
