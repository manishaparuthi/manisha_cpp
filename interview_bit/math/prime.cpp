bool checkprime(int num)
{
    bool flag=1;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            flag=0;
        }
    }
    return flag;
}
    vector<int> Solution::sieve(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> result;
    for(int i=2; i<=A;i++)
    if(checkprime(i))
    {
        result.push_back(i);
    }
    return result;
}
