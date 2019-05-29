/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-20 21:15:03 
 * @Description : Override
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-20 22:40:58
 */
#include<iostream>
using namespace std;
#include<iomanip>
#define MAXS 1025
int k;
int x,y;
int board[MAXS][MAXS];
int flag = 1;

void ChessOverride(int leftTopX,int leftTopY,int specX,int specY,int size)
{
    if(size == 1)return;
    int t = flag++;
    int s = size / 2;

    if((specX < leftTopX + s) &&( specY < leftTopY + s))//spec in left top
    {
        ChessOverride(leftTopX,leftTopY,specX,specY,s);
    }
    else
    {
        board[leftTopX+s-1][leftTopY+s-1] = t ;
        ChessOverride(leftTopX,leftTopY,leftTopX+s-1,leftTopY+s-1,s);
    }

    
    if((specX < leftTopX + s) && (specY >= leftTopY + s) )//spec in right top
    {
        ChessOverride(leftTopX,leftTopY+s,specX,specY,s);
    }
    else
    {
        board[leftTopX+s-1][leftTopY+s] = t;
        ChessOverride(leftTopX,leftTopY+s,leftTopX+s-1,leftTopY+s,s);
    }
    
    if((specX >= leftTopX+s )&& (specY < leftTopY +s) )//spec in left down
    {
        ChessOverride(leftTopX +s,leftTopY,specX,specY,s);
    }
    else
    {
        board[leftTopX+s][leftTopY+s-1] = t;
        ChessOverride(leftTopX +s,leftTopY,leftTopX+s,leftTopY+s-1,s);
    }

    if((specX >=leftTopX + s )&& (specY >= leftTopY + s) )//spec in right down
    {
        ChessOverride(leftTopX+s,leftTopY+s,specX,specY,s);
    }
    else
    {
        board[leftTopX+s][leftTopY+s]= t;
        ChessOverride(leftTopX+s,leftTopY+s,leftTopX+s,leftTopY+s,s);
    }
    
    
}


void Disp(int size)
{
    int i;
    int j;
    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size;j++)
        {
            cout<<setw(5)<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Input the k:";
    int k;
    cin>>k;
    int size  = 1 << k;
    int specX;
    int specY;
    cout<<"Input the specX and specY ";
    cin>>specX>>specY;
    ChessOverride(0,0,specX,specY,size);
    Disp(size);
    return 0;
}
