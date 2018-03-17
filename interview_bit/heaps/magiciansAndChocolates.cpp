
int Solution::nchoc(int A, vector<int> &B) {
     priority_queue<int> q;
    
    if(B.size() == 0){
        return 0;
    }
    
    for(int i = 0; i < B.size(); i++){
        q.push(B[i]);
    }
   long long int chocolates=0;
    const unsigned int M = 1000000007;
    int temp=0;
    for(int i=0;i<A;i++)
    {
        int currentmax=q.top();
        
        chocolates=chocolates+currentamax;
        chocolates=chocolates%M;
        q.pop();
       q.push(currentmax/2);
    }
    return chocolates;
}
