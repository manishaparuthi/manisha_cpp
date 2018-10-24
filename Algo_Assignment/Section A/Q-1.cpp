/*
chain length is 2 we'll fill m[1,2] m[2,3] m[3,4]  and so on.
for chain length 'l' and first index i , j will be i+l-1 and k will vary from i to j.
*/

#include<iostream> 
#include<vector>

using namespace std; 
#define INT_MAX 2147483647

int min(int a,int b)
{
     return a<b ? a:b;
}
 
int matrix_chain(vector<int> dimension) 
{ 

	
    int size=dimension.size();
    int m[size][size]; 
	 
	for (int i=1; i<size; i++) //chain length = 1 means no. of multiplications =0
		m[i][i] = 0; 
	int count=0;
	// L is chain length. or no of matrices
	for (int L=2; L<size; L++) 
	{ 
		for (int i=1; i<size-L+1; i++) 
		{ 
			int j = i+L-1; 
			m[i][j] = INT_MAX; 
			for (int k=i; k<=j-1; k++) 
			{ 
				count++;
				m[i][j] = min ( m[i][j] , m[i][k] + m[k+1][j] + dimension[i-1]*dimension[k]*dimension[j] ); 
				
			} 
		} 
	} 
	cout<<"Total no of comparisons: "<<count<<"\n";
    return m[1][size-1]; 
} 

//main
int main() 
{ 
	cout<<"Enter no. of matrices: ";
	int n,prevrow,prevcolumn,row,column;
	vector<int> dimension;
	cin>>n;
	
	bool scontinue=false;
	do
	{
	    scontinue=false;
	    cout<<"Enter dimensions of matrix "<<1<<": ";
	    cin>> prevrow>>prevcolumn;
	     dimension.push_back(prevrow);
	for(int i=1;i<n;i++)
	    {   
		cout<<"Enter dimensions of matrix "<<i+1<<": ";
		cin>> row>> column;
		if(row!=prevcolumn)
		{
			cout<<"error";
			cout<<"Enter again"<<"\n";
			scontinue=true;
			break;	
		}
		prevrow=row;
		prevcolumn=column;
		dimension.push_back(row);
		
	   }
	}while(scontinue);
	cout<<"Minimum no. of multiplications will be: "<<matrix_chain(dimension)<<"\n";
	return 0; 
} 
