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

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main function to do insertion sort
void insertionSort(int arr[], int n)
{
   
    for (int i=1;i<n;i++)
    {
      int j=i-1;
      int el=arr[i];
      while(arr[j]>el&&j>=0)
      {
        arr[j+1]=arr[j];
        j--;
      }
      arr[j+1]=el;
      cout<<" ";
      printArray(arr,n);
    }
        
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
    insertionSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}


/*void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
*/