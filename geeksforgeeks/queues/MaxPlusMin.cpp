using namespace std;
#include<iostream>
#include<vector> 
//Sum of minimum and maximum elements of all subarrays of size k.
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
int min(const vector<int> &A,int idx,int B)
{
   int min=A[idx];
   int window=idx+B;
    for (int i=idx;i<window;i++)
   {
       if(min>=A[i])
       {
           min=A[i];
       }
   }
   return min;
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
int minwindow(const vector<int> &A,int idx,int B,int prevMin)
{
   int minn=prevMin;
   if(prevMin==A[idx-1])
   {
      minn=min(A,idx,B); 
   }
   else if(A[idx+B-1]<prevMin)
   {
       minn=A[idx+B-1];
   }
   
   return minn;
}

int MaxPlusMin(const vector<int> &A, int B) 
{
    int result;
    if(B>A.size())
    {
       result=max(A,0,B)+min(A,0,B);
    }
    else
    {
        int temp1=max(A,0,B);
        int temp2=min(A,0,B);
        result=temp1+temp2;
        for(int i=1;i<A.size()-B+1;i++)
        {
            temp1=maxwindow(A,i,B,temp1);
            temp2=minwindow(A,i,B,temp2);
            result=result+temp1+temp2;
        }
    }
    return result;
}
int main()
{

	int arr[]={2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr) / sizeof(arr[0]);
 	cout<<"\nenter K: ";
 	int k;
 	cin>>k;
    vector<int> vect(arr, arr + n);
    int out=MaxPlusMin(vect,k);
	cout<<"final result: "<<out;
	return 0;
}
