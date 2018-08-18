#include<iostream>
int g=69;
int main()
{	    int a=12;
		int b=13;
		int g=14;
		int c=15;
	{
		int a=44;
		int b=36;
		int g=87;
		int c=56;
		cout<<" inside bracket\n";
		cout<<"a:"<<a<<" ";
	    cout<<"b:"<<b<<" ";
	    cout<<"g:"<<g<<" ";
	    cout<<"c:"<<c<<" ";

	}
	cout<<" outside bracket";
	cout<<"a:"<<a<<" ";
	cout<<"b:"<<b<<" ";
	cout<<"g:"<<g<<" ";
	cout<<"c:"<<c<<" ";
	cout<<"global g:";
	cout<<::g;// indicates error if g is not  defined globally
	return 0;
}

