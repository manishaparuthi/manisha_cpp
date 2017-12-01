/* Given s = "Hello World",

return 5 as length("World") = 5.
*/
int Solution::lengthOfLastWord(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //cout<<endl<<"string: "<<A;
    int i=A.size()-1;
    //cout<<endl<<"last index: "<<i;
    while(A[i]==' '&& i>=0)
    {
       // cout<<endl<<"i: "<<i;     // to remove whitespaces form end.
        i--;
    }
    int count=0;
    while(A[i]!=' '&& i>=0)
    {
        count++;
    //  cout<<endl<<"count: "<<count;
        //cout<<endl<<"i: "<<i;
        i--;
        
    }
    return count;
}
