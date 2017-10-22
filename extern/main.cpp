
#include <iostream>
using namespace std;
extern int test(int x);
int count=14;
int main()
{
 
 int  count=16; 
 cout<<"count in main is: "<<count<<endl;
 int a=4;
 int c;
 c=test(a);
 cout<<"c: "<<c;
 return 0;	
}