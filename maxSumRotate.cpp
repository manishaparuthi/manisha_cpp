//Maximum sum of i*arr[i] among all rotations of a given array
/*
Input : arr[] = {8, 3, 1, 2}
Output : 29
Explanation : Let us see all rotations
{8, 3, 1, 2} = 8*0 + 3*1 + 1*2 + 2*3 = 11
{3, 1, 2, 8} = 3*0 + 1*1 + 2*2 + 8*3 = 29
{1, 2, 8, 3} = 1*0 + 2*1 + 8*2 + 3*3 = 27
{2, 8, 3, 1} = 2*0 + 8*1 + 3*2 + 1*1 = 17

Input : arr[] = {3, 2, 1}
Output : 8
*/
#include <iostream>
#include<string>
using namespace std;
void rotate(int[],int,int);
int maxSum(int[],int);
int main()
{
	int size;
	cout<<" enter the size of the array: ";
	cin>> size;
	int arr[size];
	cout<<endl<<"enter array: "<<endl;
	for(int i=0;i<size;i++)
		{
			cin>> arr[i];
		}
	int result;
	result=maxSum(arr,size);
	cout<<"Maximum sum of i*arr[i] among all rotations of a given array: "<<result;
	return 0;
}
void rotate (int arr[],int d,int size)
{
	int temp;
	for(int i=0;i<d;i++)
	{
		temp=arr[0];
		for(int j=0;j<size;j++)
		{
			arr[j]=arr[j+1];
		}
		arr[size-1]=temp;
	}
	
}

int maxSum(int array[],int n)
{
	int temp;
	int sum[n];
	for(int i=0;i<n;i++)
		{
			sum[i]=0;
		}
	
	for(int j=0;j<n;j++)
	{
		temp=0;
		rotate(array,1,n);
		cout<<endl<<" array in this iteration is: ";
		for(int i=0;i<n;i++)
		{
			cout<<array[i]<<" ";
		}
		//cout<<endl;
		cout<<"temp value: ";
		for(int i=0;i<n;i++)
		{
			temp=temp+i*array[i];
			cout<<temp<<" ";
		}
		sum[j]=temp;
	}
	cout<<endl<<"sum array: ";
	for(int i=0;i<n;i++)
		{
			cout<<sum[i]<<" ";
		}
		cout<<endl;

  int curr_max=sum[0];
  for(int i=0;i<n;i++)
  {
  	if(curr_max<sum[i])
  	{
  		curr_max=sum[i];
  	}
  }
	return curr_max;
}