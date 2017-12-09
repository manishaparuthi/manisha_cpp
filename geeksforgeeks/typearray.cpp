using namespace std;
#include<iostream>
int max(int array[],int size)
{
	int max=array[0];
	int maxidx=0;
	for (int i=1;i<size;i++)
	{
		if(array[i]>max)
		{
			maxidx=i;
			max=array[i];
		}
	}
	return maxidx;
}
int typeArray(int array[],int size)
{
	int maxidx;
	maxidx=max(array,size);
	int dir;
	if(maxidx==0||maxidx==size-1)//ascending or descending.
	{
		if(maxidx==0)
		{
		    if(array[2]<array[size-1])
			{
				dir=4;
			}
			else
			{
			    dir=2;//descending
	    	//	cout<<"Descending";
			}

		}
		else
		{
			if(array[0]>array[size-2])
			{
				dir=3;
			}
			else
			{
			    dir=1;//ascending
		//	cout<<"ascending";
			}
		}
	}
	else
	{
		if(array[maxidx-1]>array[maxidx+1])
		{
			dir=4;//ascending rotated
			//cout<<"ascending rotated";
		}
		else if(array[maxidx-1]<array[maxidx+1])
		{
			dir=3;//descending rotated
			//cout<<"descending rotated";
		}

	}
	//cout<<" max element";
	return dir;

}
int main()
{
	int t;
	cin>>t;
	int maxo[t];
	int diro[t];
	int i=0;
	int size;
//	int maxel;
	//int type;
	while(i<t)
	{
	   cin>>size;
	   //cout<<endl;
	   int array[size];
	   for(int i=0;i<size;i++)
	   cin>>array[i];
	   maxo[i]=array[max(array,size)];
	   diro[i]=typeArray(array,size);
	   i++;
	   
	}
	for(int i=0;i<t;i++)
	{
	    //cout<<endl;
	    cout<<maxo[i]<<" "<<diro[i];
	    cout<<endl;
	}
	return 0;
}
