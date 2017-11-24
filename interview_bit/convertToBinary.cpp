string Solution::findDigitsInBinary(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  
    string ans;
    int quot;
    int rem;
    if(A==1||A==0)
    {
        ans=to_string(A);
        return ans;
    }
    while(A>0)
    {
        rem=A%2;
       // cout<<"rem: "<<rem;
        ans += to_string(rem);
        
        
       // cout<<endl<<"ans: "<<ans;
        A=A/2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
