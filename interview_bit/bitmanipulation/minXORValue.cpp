int Solution::findMinXor(vector<int> &A) {
    
    int size = A.size();
    sort(A.begin(),A.end());
    int min_xor=INT_MAX;
    for(int i =0 ; i < size-1; i++)
    {
        if((A[i]^A[i+1]) < min_xor)
        {
            //cout<<"here \n";
            min_xor = A[i]^A[i+1];
        }
    }
    return min_xor;
    
}
