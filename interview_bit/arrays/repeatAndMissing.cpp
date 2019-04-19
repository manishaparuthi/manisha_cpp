vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int X = 0;
   
    
    int n = A.size();
    for( int i = 0 ; i < n ; i++)
    {
        X^=A[i];
        
    }
    for( int i = 1 ; i <= n ; i++)
    {
        X^=i;
        
    }
    int set_bit_no = X & -X; //choose one set bit ,here we are choosing rightmost set bit
  
    int x = 0, y = 0; // two numbers 
    for (int i = 0; i <= n-1; i++) 
    { 
        if (A[i] & set_bit_no) 
            x = x ^ A[i]; 
        else
            y = y ^ A[i]; 
    } 
    for (int i = 1; i <= n; i++) 
    { 
        if (i & set_bit_no) 
            x = x ^ i; 
        else
            y = y ^ i; 
    } 
    
  int flagx=0;
  for(int i = 0 ; i < n ; i ++)
  {
      if(x==A[i]){
          flagx=1;
          break;
      }
  }
   vector<int>result;
  
  if(flagx){
      result.push_back(x);
      result.push_back(y);
  }
  
  else{
    result.push_back(y);
    result.push_back(x);
  }
    return result;
}
