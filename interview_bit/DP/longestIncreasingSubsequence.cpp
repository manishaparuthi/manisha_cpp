int Solution::lis(const vector<int> &A) {
    int size = A.size();
    vector <int> LIS(size,1);
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if((A[i] > A[j]) && (LIS[i] < LIS[j] + 1))
            {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    int max = LIS[0];
    for(int i = 0 ;i < size ; i++)
    {
        if(max < LIS[i]){
            max = LIS[i];
        }
    }
    return max;
}
