// merge 2 sorted arrays
#include <iostream>
void merge(int[], int,int[],int,int[]);
void print_array(int[],int);
int main()
{
	int arr1[]={23,39,56,101,234};
  cout<<"the elements of first array are:";
  print_array(arr1,5);
	int arr2[]={12,17,45,78,89,94,134};
  cout<<endl<<"the elements of second array are:";
  print_array(arr2,7);
	int sorted_array[12]={0};
	merge(arr1,5,arr2,7,sorted_array);
  cout<<endl<<"the array after merging is:";
	print_array(sorted_array,12);
  return 0;

}
void merge(int array1[],int size1,int array2[],int size2,int array3[])
{
  int i=0;
  int j=0;
  int k=0;
  while(i<size1 && j<size2)
  {
  	if(array1[i]>array2[j])
  	{
  		array3[k]=array2[j];
  		j++;
  		//k++;
  	}
  	else
  	{
  		array3[k]=array1[i];
  		i++;
  		//k++;
  	}
  	k++;
  }
  while(i<size1)
  {
  array3[k]=array1[i];
  i++;
  k++;
  }
while(j<size2)
{
  array3[k]=array2[j];
  j++;
  k++;
}

}
void print_array(int array[],int size)
{
	//cout<<"The elements of array are:";
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";

	}
}