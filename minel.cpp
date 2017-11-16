/*Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
PROBLEM APPROACH:

Note: If you know the number of times the array is rotated, then this problem becomes trivial. If the number of rotation is x, then minimum element is A[x].
Lets look at how we can calculate the number of times the array is rotated.
*/
using namespace std;
#include<iostream>
int main()
{
	cout<<"Enter size of the array: ";
	int size;
	cin>>size;
	int array[size];
	cout<<"Enter Sorted Array: ";
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	//main logic.
	int min=array[0];
	int  i=1;
	int rot=0;
	while(i<size)
	{
		if(    (array[i]<array[i-1])  &&
			(array[i]<array[i+1])    )
		{
			min=array[i];
			rot=i;
			break;
		}
		i++;
	}
	cout<<" array is rotated at: "<<rot;
	cout<<endl<<"minimum element is: "<<min;
	return 0;

}