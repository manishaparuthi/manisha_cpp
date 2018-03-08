using namespace std;
#include<iostream>
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int removeDuplicates(int arr[],int n)
{
	int i=1;
	int temp=0;
	int j;
	while(i<n)
	{

		while(arr[i]==arr[i-1])
		{
			i++;
		}

		if(i<n)
	   {
			j=i;
		    temp++;
		    arr[temp]=arr[j];
		    cout<<"\nj: "<<j;
		    cout<<"\ntemp: "<<temp;
		    i=j+1;
	  }
	}
	temp++;
	arr[temp]=arr[n-1];
	return temp;
}
// Driver program
int main()
{
 
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array: ";
    for (int i=0; i<n; ++i)
    {
        cin>> arr[i] ;
    }
    int index=removeDuplicates(arr, n);

 
    cout << "Resultant array is \n";
    printArray(arr, index);
    return 0;
}
