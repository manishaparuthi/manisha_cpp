vector<int> Solution::wave(vector<int> &A) {
    int size = A.size();
    int temp;
    
    // O(n) approach
    
    
    // for(int i = 0 ; i < size ; i = i+2)
    // {
    //     if((i > 0) && (A[i] > A[i-1]))
    //     {
    //         temp = A[i];
    //         A[i] = A[i-1];
    //         A[i-1] = temp;
    //     }
    //     if( (i<size-1) && (A[i] > A[i+1]))
    //     {
    //         temp = A[i];
    //         A[i] = A[i+1];
    //         A[i+1] = temp;
    //     }
    // }
    
    
    //lexographically smallest  nlogn approach
    
    
    sort(A.begin(), A.end());
    for (int i=0; i<size-1; i += 2) 
    {    temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp; 
    }
    return A;
}
