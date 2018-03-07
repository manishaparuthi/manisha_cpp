using namespace std;
#include<iostream>
#include<vector> 
//first negative integer in winow size k
int negative(const vector<int> &A,int idx,int B)
{
   int neg=0;
   int window=idx+B;
    for (int i=idx;i<window;i++)
   {
       if(A[i]<0)
       {
           neg=A[i];
           break;
       }
   }
   return neg;
}

int negativewindow(const vector<int> &A,int idx,int B,int prevNeg)
{
   int negt=prevNeg;
   if(prevNeg==A[idx-1])
   {
      negt=negative(A,idx,B); 
   }
   
   return negt;
}

vector<int> FirstNegative(const vector<int> &A, int B) 
{
    vector<int> result;
    if(B>A.size())
    {
       result.push_back(negative(A,0,B));
    }
    else
    {
        int temp=negative(A,0,B);
        
        result.push_back(temp);
        for(int i=1;i<A.size()-B+1;i++)
        {
          if(temp!=0)
            {
              temp=negativewindow(A,i,B,temp);
              result.push_back(temp);
            }
            else
            {
              temp=negative(A,i,B);
              result.push_back(temp);
            }
        }
    }
    return result;
}
int main()
{

	int arr[]= {12, -1, -7, 8, -15, 30, 16, 28} ;
	int n = sizeof(arr) / sizeof(arr[0]);
 	cout<<"\nenter K: ";
 	int k;
 	cin>>k;
    vector<int> vect(arr, arr + n);

    vector<int> v=FirstNegative(vect,k);
	cout<<"final result: \n";
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<" ";
  }
	return 0;
}
