/* Given a positive integer which fits in a 32 bit signed integer, 
find if it can be expressed as A^P where P > 1 and A > 0.
A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4.   */

int calcpower(int base,int exponent)  // function to calculate power.
{
    int ans=1;
for(int i=1;i<=exponent;i++)
{
    ans=ans*base;
    
}
return ans;
}
 bool Solution::isPower(int A) {
        bool result=0;
    
    if(A==1)
    {
        return 1;
    }
    
    
    for(int i=2;i<=sqrt(A);i++)
    {
       // cout<<endl<<"i: "<<i;
        for(int j=2;j<32;j++)    // this loop is executed 32 times because integer is 32 bit.(if we try to calculate power(x,33) it will
                                  //lead to zero.
        {
          //  cout<<endl<<"j: "<<j;
            //cout<<endl<<"pow: "<<calcpower(i,j);
            if(calcpower(i,j)==A)
            {
                result=1;
            }
        }
    }
    return result;
}
