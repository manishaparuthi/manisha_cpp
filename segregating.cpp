using namespace std;
#include<iostream>
void segregate(int [],int );
void segregate0n1(int [],int );
void print_array(int[],int);
int main()
{
	int  array[]={1,0,0,1,0,1,0};
	int array1[]={1,1,1,1,1,1,0,0,0,0};
	print_array(array,7);

	cout<<endl;
	print_array(array1,10);
	segregate(array,7);
	cout <<endl;
	segregate0n1(array1,10);
	print_array(array,7);
	print_array(array1,10);
	return 0;
}

void print_array(int array[],int size)
{
	cout<<"The elements of array are:";
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";

	}
}
void segregate(int array[],int size)
{
   int count=0;

for (int i=0;i<size;i++)
	{
		if(array[i]==0)
		{
			count++;
		}
	}
	for (int i=0;i<count;i++)
	{
		array[i]=0;
	}
	for (int i=count;i<size;i++)
	{
		array[i]=1;
	}

}
void segregate0n1(int array[],int size)
{
	int left=0;
	int right=size-1;
	while(left<right)
	{
		while(array[left]==0 && left<right)
		{
			left++;
		}
		while(array[right]==1 && left<right)
		{
			right--;
		}
		if(left<right)
		{
			array[left]=0;
			array[right]=1;
			left++;
			right--;
		}
	}






}