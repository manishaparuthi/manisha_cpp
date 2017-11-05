//  to check a no if it is a power of two
#include<iostream>
using namespace std;
bool checkPowerTwo(int);
int main()
{
	int num;
	cout<<" enter number: ";
	cin>>num;
	bool x;
	x=checkPowerTwo( num);
	if(x)
	{
		cout<<"yes;";
	}
	else if(!x)
	{
		cout<<" no!!";
	}
	return 0;

}
bool checkPowerTwo(int number)
{
	int rem;
	if(number==0)
	{
		return false;
	}
	while(number!=1)
	{
		rem=number%2;
		if(rem==1)

		{
			return false;
		}
		number=number/2;

	}
	return true;
	
}
