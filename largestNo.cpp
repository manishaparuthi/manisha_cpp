//Largest number with given sum
using namespace std;
#include <iostream>
int power(int base,int exponent)
{
	int ans=1;
	for(int i=0;i<exponent;i++)
	{
		ans=ans*base;
	}
	return ans;
}

int main()
{
	int number;
	int add;
	cout<<" enter number of digits : ";
	cin>> number;
	cout<<" enter sum of digits: ";
	cin>>add;
	int temp;
	int result=0;
	 if(add>number*9)
	 {
	 	cout<<"no such number  exist:";
	 
	 }
	 else
	 {


	while(number>0)
	{
		temp=power(10,number-1);
		if(add>=9)
		{
			//cout<<" temp is: "<< temp;
			temp=temp*9;
			//cout<<"multiplying: "<<temp;
			add=add-9;
			result=result+temp;
			//cout<<" rsult: "<<result;
		}
		else if(add<9)
		{
			//cout<<" temp is: "<< temp;
			temp=temp*add;
			//cout<<"multiplying: "<<temp;
			result=result+temp;
			//cout<<" rsult: "<<result;
			break;
		}
		number=number-1;
	}// end while
	cout<<endl;
	cout<<"largest number with given sum of digits is: "<<result;
  }// end else
 return 0;
}
