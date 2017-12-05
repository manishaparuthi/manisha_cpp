/*
Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
          11000000000000000000000000000000
return 3221225472
*/
int pow(int base,int exponent)
{
    int result=1;
    for(int i=1;i<=exponent;i++)
    {
        result=result*base;
    }
    return result;
}
    unsigned int Solution::reverse(unsigned int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int temp;
    int soln=0;
    int i=31;
  //  cout<<"power: "<<pow(4,2);
    while(A!=0)
    {
      temp=A%2;
      if(temp==1)
      {
          soln=soln+pow(2,i);
      }
      i--;
      A=A/2;
      
    }
    return soln;
}
