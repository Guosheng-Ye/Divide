/*================================================================
*  @FileName:SumOfTree.cpp
*  @Author  : YeGuosheng 
*  @CreateTime : 2019-03-23 07:29:19
*  @Description: 
* suppose binary tree is stored in binary chain storage structure, and the node value is of type int.
* design a recursive algorithm to find the sum of all leaf node values in the binary tree bt
*  @Last Modified time: 2019-03-23 15:39:08
================================================================*/

#include<iostream>
using namespace std;
#include<malloc.h>

typedef struct node
{
    /* data */
    int data;
    struct node * lchild;
    struct node * rchild;
}BtreeNode;

void CreateBtree(BtreeNode *& B)
{
    B = NULL;
    
    char ch;
    ch = getchar();
    if(ch == '#')
        B = NULL;
    else
    {
        B = (BtreeNode*)malloc(sizeof(BtreeNode));
        B->data = ch-48;
        CreateBtree(B->lchild);
        CreateBtree(B->rchild);
    }
}

void Destory(BtreeNode *&B)
{
    if(B != NULL)
    {
        Destory(B->lchild);
        Destory(B->rchild);
        free(B);
    }
}

int  LeafSum(BtreeNode *B)
{
    if(B == NULL)
    {
        return 0;
    }
    else if(B->lchild == NULL &&  B->rchild == NULL)
    {
        return B->data;
    }
    else
    {
        int leftLeafSum = LeafSum(B->lchild);
        int rightLeafSum = LeafSum(B->rchild);
        return (leftLeafSum + rightLeafSum);
    }
} 

int main()
{
    BtreeNode *B;
    CreateBtree(B);
    int leafSum = LeafSum(B);
    cout<<"Leaf of Sum = "<<(LeafSum(B))<<endl;
    Destory(B);
    return 0;
}
