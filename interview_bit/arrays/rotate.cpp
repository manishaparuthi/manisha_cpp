void rot(vector<vector<int> > &A,int row_start,int row_end,int col_start,int col_end)
{
    int i;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    while(row_start<row_end)
    {
        i=0;
        
            while(row_start+i<row_end)
            {
                temp1=A[row_start+i][col_start];
                temp2=A[row_end][col_start+i];
                temp3=A[row_end-i][col_end];
                temp4=A[row_start][col_end-i];
                A[row_start+i][col_start]=temp2;
                A[row_end][col_start+i]=temp3;
                A[row_end-i][col_end]=temp4;
                A[row_start][col_end-i]=temp1;
                i++;
                
            }
        row_start++;
        col_start++;
        row_end--;
        col_end--;
    }
}
void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int size=A.size();
    rot(A,0,size-1,0,size-1);
}
