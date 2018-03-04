// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void swap(int *a,int *b)
{

     int temp;
     temp = *b;
     *b = *a;
     *a = temp; 

}

// main function to do bubble sort
void bubbleSort(int arr[], int n)
{
   
    for (int i = 0; i < n ; i++)
    {
       for(int j = 0 ; j < n-i ; j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(&arr[j],&arr[j+1]);
            }
           
        }
    }
        
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
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
    bubbleSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}