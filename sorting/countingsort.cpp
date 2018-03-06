// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main function to do count sort
void countingSort(int arr[], int n,int range)
{
   
   int count[range+1];
   for(int i=0;i<=range;i++)
   {
       count[i]=0;
   }

   int output[n];
   for(int i=0;i<n;i++)
   {
      count[arr[i]]++;
   }
   //cout<<"\ncount Array ";
   //printArray(count,range+1);
   for(int i=1;i<=range;i++)
   {
      count[i]=count[i-1]+count[i];
   }
   //cout<<"\ncount Array ";
   //printArray(count,range+1);
   for(int i=0;i<n;i++)
   {
       int temp=count[arr[i]];
       output[temp-1]=arr[i];
       count[arr[i]]--;
       //cout<<"\ncount array after iteration "<<i<<" is: ";
       //printArray(count,range+1);
   }
    for(int i=0;i<n;i++)
   {
       arr[i]=output[i];
   }

}
 

 
// Driver program
int main()
{
    cout<<"\t\t\t-#-#-#COUNTING SORT#-#-#-";
    int n;
    cout<<"\nEnter size of array: ";
    cin>>n;
    int arr[n];
    int range;
    cout<<"\nEnter RANGE: ";
    cin>>range;
    cout<<"\nEnter array: ";
    for (int i=0; i<n; ++i)
    {
        cin>> arr[i] ;
    }
    countingSort(arr, n,range);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}