// add one to the number
using namespace std;
#include<iostream>
bool powerOf2(int );
int main()
{
    int number;
    cout<<"Enter number: ";
    cin>>number;
    cout<<endl;
    cout<<powerOf2(number);
    cout<<endl;
    return 0;
}
bool powerOf2(int x)
{
    if(x==0)//00000001
    {
      return x;
    }
    else
    {
      return !(x & (x-1));//bit wise and.
    }
}

