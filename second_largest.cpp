// second largest element in array
# include<iostream>
using namespace std;
int main()
{
	int arr[7]={4,2,1,6,9,78,43};
	int max=arr[0],secmax=arr[0];
	for (int i=0;i<7;i++)
	{
		if(arr[i]>max)//current element is greater than both max and secmax.
		{
			secmax=max;
			max=arr[i];

		}
		else if(arr[i]>secmax)//current element is between max and sec max
		{
			secmax=arr[i];
		}
	}
	cout<<"max element is:"<<max<<" and second largest element is:"<<secmax;
	return 0;
}