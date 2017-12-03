/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/
int Solution::isPalindrome(string A)
{
    // Do not write main() function.
    int result=1;
    int length =A.size();
    int first=0;
    int last=length-1;
    while(first<last)
    {
        
        if(isalnum(A[first])&&isalnum(A[last]))
        {
            if(tolower(A[first])==tolower(A[last]))
            {
                first++;
                last--;
            }
            else
            {
                result=0;
                break;
            }
        }
        else if(isalnum(A[first]))
        {
            last--;
        }
        else
        {
            first++;
        }
       
      
    }
    return result;
}
