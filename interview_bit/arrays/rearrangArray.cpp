void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size = A.size();
    for( int i = 0 ; i < size ; i++)
    {
        A[i] = A[i] + (A[A[i]] % size)*size;
        
    }
    for( int i = 0 ; i < size ; i++)
    {
        A[i] = A[i]/size ;
        
    }
}
/*
A = B + C*n
A/n = C
A%n = B

*/
