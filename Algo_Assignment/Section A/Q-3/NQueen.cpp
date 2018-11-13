

#include<iostream>
using namespace std;

int solutionno=0;
void printSolution(int* board,int N) //for printing board
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        {
	    if( *(board + i*N + j))
                cout<<"\tQ";
	    else
                cout<<"\t-";
        } 
        cout<<"\n"; 
    } 
} 
  

bool isSafe(int *board, int row, int col,int N) //to check is it safe to place queen at board[row][col]
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
    if (col == N) 
    {
        
        cout<<"\n\n-----------------------solution " <<++solutionno<<"-------------------------------------\n\n";
        printSolution(board,N);
        return true;  
    }
  
   bool res=false;
    for (int i = 0; i < N; i++) 
    { 
        
        if ( isSafe(board, i, col,N) ) //check at board[i][col]
        { 
            
            *(board + i*N + col) = 1; 
  
            res = NQueenHelper(board, N,col + 1) || res;
            
  
            *(board + i*N  + col) = 0; // BACKTRACK 
        } 
    } 
  
     
    return res; 
} 
  

bool NQueen(int N) 
{ 
    int board[N][N];
    for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	   board[i][j]=0;
  
    if ( NQueenHelper(*board,N, 0) == false ) 
    { 
      cout<<"Solution does not exist"; 
      return false; 
    } 
  
   
    return true; 
} 
  
// driver program to test above function 
int main() 
{ 
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"\n\n-----------------POSSIBLE SOLUTIONS----------------------------\n\n";
    NQueen(n); 
    return 0; 
} 
