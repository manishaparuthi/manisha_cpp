int Solution::findMinXor(vector<int> &A) {
    int min_xor=A[0]^A[1];
    int temp;
     for (int it = 0 ; it < A.size(); ++it)
    {
        for (int jt = it+1 ; jt<A.size(); ++jt)
        {
           temp=A[it]^A[jt];
           if(temp<min_xor)
           {
               min_xor=temp;
           }
        }
    }
    return min_xor;
    
}





