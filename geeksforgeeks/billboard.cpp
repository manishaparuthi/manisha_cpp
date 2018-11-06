using namespace std;
#include <iostream>

void printBillBoard(int x[],int k,bool billboard_no[]) {

	cout << "\n BillBoard should be placed (Position) at : ";
	
	cout << endl;
}
int max(int a,int b)
{
	return a < b ? b : a;
}
int billboardConst( int M, int n, int x, int position[], int revenue[] ) 
{

	int maxRev[M+1];
	bool billboardPos[n];

	for ( int i=0; i <= M; i++) {
		maxRev[i] = 0;
	}
	int next = 0;

	
	for( int i=0; i < n; i++ ) 
		billboardPos[i] = 0;


	for ( int i = 1; i <= M; i++ ) 
	{

		if ( next < n ) 
		{
			if ( position[next] != i ) 
			{

				maxRev[i] = maxRev[i-1];
			}

			else 
			{
				if ( i <= x ) 
				{ 

					// to choose/ignore the starting billboard which are less than or equal to 5 miles apart
					
						maxRev[i] = max(maxRev[i-1],revenue[next]);
				}

				else 
				{
						maxRev[i] = max(maxRev[i-x-1]+revenue[next],maxRev[i-1]);
						
				}
				next++;
			}

			
				
			}
		

		else
			maxRev[i] = maxRev[i-1];
	
	}


	next = n-1;
	int value = maxRev[M];
	
	//Finding BillBoard No which are being placed.
	for ( int i = M-1; i >= 0 ; i-- ) {
		
		if ( value == maxRev[i] && maxRev[i] > 0 ) {

				while ( value == maxRev[i] )
					i--;

				while ( next >= 0 ) {
					if ( position[next] == i+1 ) {
						billboardPos[next] = 1;
						value -= revenue[next];
						break;
					}
					next--;
				}
		}
	}

	//Printing BillBoard No which are being placed.
	for ( int i=0; i < n; i++) {
		if ( billboardPos[i] == 1 ) {
			cout << i << " ";
		}
	}

	return maxRev[M];
}

int main () 
{
	cout<<"Enter M:";
	int M;
	cin>>M;

	cout<<"Enter minimum distance between 2 billboards:";
	int x;
	cin>>x;

	cout << "\nEnter Number of billboards: ";
	int n;
	cin >> n;
    int position[n], revenue[n];

	cout<<"\n Enter Position,revenues :\n ";
	for ( int i=0; i<n; i++ ) 
	{
		cout<<"\n-------------Billboard "<<i+1<<"-----------";
		cout <<"\nPosition: ";
		cin >> position[i];
		cout <<"\nRevenue: ";
		cin >> revenue[i];
	}

	
	int maxRevenue = billboardConst (M, n, x, position, revenue);

	cout << "\n The maximum revenue obtained : "<<maxRevenue << endl;


	return 0;
}
