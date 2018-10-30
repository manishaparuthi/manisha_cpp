

#include<iostream>
using namespace std;


//print
void printSolution(int* board,int N) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", *(board + i*N + j)); 
        printf("\n"); 
    } 
} 
  

bool isSafe(int *board, int row, int col,int N) 
{ 
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if ( *(board + row*N + i) ) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (*(board + i*N + j)) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (*(board + i*N + j)) 
            return false; 
  
    return true; 
} 
  
/* A recursive utility function to solve N 
   Queen problem */
bool NQueenHelper(int *board,int N, int col) 
{ 
    if (col >= N) 
        return true; 
  
   
    for (int i = 0; i < N; i++) 
    { 
        
        if ( isSafe(board, i, col,N) ) //check at board[i][col]
        { 
            
            *(board + i*N + col) = 1; 
  
            
            if ( NQueenHelper(board,N, col + 1) ) 
                return true; 
  
            *(board + i*N  + col) = 0; // BACKTRACK 
        } 
    } 
  
     
    return false; 
} 
  

bool NQueen(int N) 
{ 
    int board[N][N];
    for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	   board[i][j]=0;
  
    if ( NQueenHelper(*board,N, 0) == false ) 
    { 
      printf("Solution does not exist"); 
      return false; 
    } 
  
    printSolution((int *)board,N); 
    return true; 
} 
  
// driver program to test above function 
int main() 
{ 
    int n;
    cout<<"Enter n: ";
    cin>>n;
    solveNQ(n); 
    return 0; 
} 

