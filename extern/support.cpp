#include <iostream>
using namespace std;
extern int count;
int count=17;
 int test(int x)
{   
	cout<<"calling function:"<<endl;
	int count=13;
	cout<<" count in function is: "<<count;
	return x*x;
}