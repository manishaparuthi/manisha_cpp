int Solution::longestSubsequenceLength(const vector<int> &A) 
{
    int size = A.size();
    if(size == 0)
    {
        return 0;
    }
    vector <int> LIS(size,1);
    vector <int> LDS(size,1);
    for (int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(A[i] > A[j] && (LIS[i] < LIS[j] + 1))
            {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    
    for (int i = size-2 ; i >=0 ; i--)
    {
        for(int j = size-1 ; j > i ; j--)
        {
            if(A[i] > A[j] && (LDS[i] < LDS[j] + 1))
            {
                LDS[i] = LDS[j] + 1;
            }
        }
    }
    int max = LIS[0] + LDS[0] - 1;
    for (int i = 1 ;  i< size ; i++)
    {
        if((LIS[i] + LDS[i] - 1) > max)
            max = LIS[i] + LDS[i] - 1;
    }
    return max;
    
}
