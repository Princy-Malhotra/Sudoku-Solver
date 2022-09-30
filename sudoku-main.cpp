
/*
 *=====================
 *   SUDOKU SOLVER
 *=====================
 *
 * Started On - FEBRUARY 16, 2022
 * Author - PRINCY MALHOTRA
 * Objective - Takes in Sudoku puzzles and outputs the solution.
*/

// INPUT FORMAT - THE PROGRAM TAKES A 9*9 SUDOKU MATRIX AS INPUT FROM THE USER. THE CELLS AT WHICH THE VALUE IS NOT KNOWN ARE INDICATED BY 0 AND REST OTHER CELLS BY 
//			THEIR KNOWN VALUE
// OUTPUT FORMAT - RETURNS "NO SOLUTION POSSIBLE" IF THE GIVEN SODUKU HAS NO SOLUTION, OTHERWISE RETURNS THE SOLVED MATRIX


#include<bits/stdc++.h>
using namespace std;


/* This is a function to check if the sudoku matrix is a valid one if we place
 the value 'val' at 'row'th row and 'col'th column of the matrix */
// For this, we are going to check if 'val' already exists in the 'row' or the 'col', and then in the 3*3 sub-matrix 
bool isValidSoduku(int** board,int row,int col,int val)
{
	// Checking if 'val' already exists in the row 'row'
	// If 'val' is found, we return false as it would not be valid to place 'val' in that row again
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==val)
            return false;
    }
    
	
	// Checking if 'val' already exists in the column 'col'
	// If 'val' is found, we return false as it would not be valid to place 'val' in that column again
    for(int j=0;j<9;j++)
    {
        if(board[j][col]==val)
            return false;
    }
    
	// Checking if 'val' already exists in the 3*3 sub-matrix in which 'row' row and 'col' column will lie
	// If 'val' is found, we return false as it would not be valid to place 'val' in that sub-matrix again
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
	
	// In case 'val' is not found in the above three cases, we return true
    return true;
}

bool solveSoduku(int** board,int i,int j)
{
	// If we reach the end of the soduku matrix, we return true
	if(i==8 && j==9)
    {
        return true;
    }
    
	// If next column to be checked is 9, then we need to move to the next row as the matrix is 9*9 only
    if(j==9)
    {
        i++;
        j=0;
    }
    
	// If board[i][j] already has some non-zero value, we cannot change it and we will move to the next column
    if(board[i][j]!=0)
    {
        return solveSoduku(board,i,j+1);
    }
    
	// One by one, we place value from 1 to 9 in the cell and check if the resulting matrix is valid and can solved completely. If so, we return true, else
	// we return false.
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
		//Finding the first zero-valued cell
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
            cout<<"NO SOLUTION POSSIBLE"<<endl;
    }
    else{
        cout<<"NO SOLUTION POSSIBLE"<<endl;
    }
}
