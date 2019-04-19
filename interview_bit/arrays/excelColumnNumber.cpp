int Solution::titleToNumber(string A) 
{
    int result = 0;
    int size = A.length();
    int pos = 0;
    for(int i = size - 1 ; i >=0 ; i--)
    {
        result += (A[i]-64)*pow(26,pos);
        pos++;
    }
    return result;
}

/* convert a number (base 26) to decimal */
