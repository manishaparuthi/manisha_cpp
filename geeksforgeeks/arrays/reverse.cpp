using namespace std;
#include <iostream>
void swap(int *a,int *b)
{

     int temp;
     temp = *b;
     *b = *a;
     *a = temp; 

}
void reverseArray(int array[],int size)
{
	for(int i=0;i<size/2;i++)
	{
		swap(&array[i],&array[size-i-1]);;
	}
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

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
    reverseArray(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}
