/* Given an array of integers, return indices of the two numbers such that 
they add up to a specific target.You may assume that each input would have
 exactly one solution, and you may not use the same element twice.
*/
using namespace std;
#include<iostream>
int main()
{
	int size;
	cout<<"Enter the size of the Array: ";
	cin>>size;
	int target;
	cout<<endl;
	cout<<"Enter the Target value: ";
	cin>>target;
	cout<<endl;
	int array[size];
	int result[2];
	cout<<"Enter Array: ";
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	for (int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			if(array[i]+array[j]==target)
			{
				result[0]=i;
				result[1]=j;
				break;
			}
		}
	}
	cout<<endl;
	cout<<"The Resultant values are: ";
	cout<<result[0]<<" "<<result[1];
	return 0;
}