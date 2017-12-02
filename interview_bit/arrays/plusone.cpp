/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.
*/
vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=A.size()-1;
    int carry=1;
    while(carry==1&&i>=0)
    {
        if((A[i]+1)>9)
        {
           A[i]=0;
           i--;
          
        }
        else
        {
            A[i]=A[i]+1;
        carry =0;
        }
    }
    if(A[0]==0&&carry==1)
    {
        A.push_back(1);
        reverse(A.begin(),A.end());
    }
    
     i=0;
    while(A[i]==0)
    {
        
        i++;
    }
    A.erase(A.begin(),A.begin()+i);
    
    return A;
}
