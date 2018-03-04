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

// main function to do selection sort
void selectionSort(int arr[], int n)
{
   
    for (int i = 0; i < n ; i++)
    {
        int small=arr[i];
        for(int j = i ; j < n ; j++)
        {
            if(arr[j]<small)
            {
                swap(&arr[j],&small);
            }
           
        }
         swap(&arr[i],&small);
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
    selectionSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}
