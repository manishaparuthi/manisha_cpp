int max(const vector<int> &A,int idx,int B)
{
   int max=A[idx];
   int window=idx+B;
    for (int i=idx;i<window;i++)
   {
       if(max<=A[i])
       {
           max=A[i];
       }
   }
   return max;
}
int maxwindow(const vector<int> &A,int idx,int B,int prevMax)
{
   int maxn=prevMax;
   if(prevMax==A[idx-1])
   {
      maxn=max(A,idx,B); 
   }
   else if(A[idx+B-1]>prevMax)
   {
       maxn=A[idx+B-1];
   }
   
   return maxn;
}

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    vector<int> result;
    if(B>A.size())
    {
       result.push_back(max(A,0,A.size())); 
    }
    else
    {
        int temp=max(A,0,B);
        result.push_back(temp);
        for(int i=1;i<A.size()-B+1;i++)
        {
            temp=maxwindow(A,i,B,temp);
            result.push_back(temp);
        }
    }
    return result;
}
