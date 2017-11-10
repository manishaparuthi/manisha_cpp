using namespace std;
#include<iostream>
int main()
{
	int t;
	cout<<"enter no.of test cases: ";
	cin>>t;
	int array[t];
	for (int i=0;i<t;i++)
	cin>> array[i];
	int i=0;
	while(i<t)
	{
		cout<<endl;
	
	//cout<<endl;
    int count0=0;
	int count1=0;
	int n=array[i];
	int remainder;
	while(n != 0)
	{
		remainder=n%10;
		if(remainder==1)
		{
			count1++;
		}
		else 
			count0++;
		
		n=n/10;
	}



	if(count0==1||count1==1)
	{
		cout<<"yes";
	}
	else
		cout<<"no";
	i++;
}
	return 0;
}