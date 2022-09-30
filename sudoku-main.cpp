#include<bits/stdc++.h>
using namespace std;

bool isValidSoduku(int** board,int row,int col,int val)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==val)
            return false;
    }
    
    for(int j=0;j<9;j++)
    {
        if(board[j][col]==val)
            return false;
    }
    
    int stx,ex,sty,ey;
    if(row%3==0) {stx = row; ex = row+2;}
    else if(row%3==1) {stx = row-1; ex = row+1;}
    else if(row%3==2) {stx = row-2; ex = row;}
    if(col%3==0) {sty = col; ey = col+2;}
    else if(col%3==1) {sty=col-1; ey = col+1;}
    else if(col%3==2) {sty = col-2; ey = col;}
    
    for(int i=stx;i<=ex;i++)
    {
        for(int j=sty;j<=ey;j++)
        {
            if(board[i][j]==val)
                return false;
        }
    }
    return true;
}

bool solveSoduku(int** board,int i,int j)
{
	if(i==8 && j==9)
    {
        return true;
    }
    
    if(j==9)
    {
        i++;
        j=0;
    }
    
    if(board[i][j]!=0)
    {
        return solveSoduku(board,i,j+1);
    }
    
    for(int k=1;k<=9;k++)
    {
        //board[i][j]=k;
        if(isValidSoduku(board,i,j,k))
        {
            board[i][j]=k;
            if(solveSoduku(board,i,j+1))
                return true;
        }
        
        board[i][j]=0;
    }
    return false;
}

int main(){
    
    // write your code here
    int** board = new int*[9];
    for(int i=0;i<9;i++)
        board[i]=new int[9];
    
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>board[i][j];
        }
    }
    int i,j,p=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                p=1;
                break;
            }
        }
        if(p==1)
            break;
    }
    if(p==1)
    {
        if(solveSoduku(board,i,j))
        {
            //cout<<"true"<<endl;
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else
            cout<<"false"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}