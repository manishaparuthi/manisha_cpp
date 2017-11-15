using namespace std;
#include<iostream>

    
int countDigit(int x)
    {
        int count =-1;
        while(x!=0)
        {
          count++;
            x=x/10;
        }
        return count;
    }
    int power(int base,int exp)
    {
        int result=1;
        for(int i=0;i<exp;i++)
        {
            result=result*base;
        }
        return result;
    }
int reversel (int x) 
{
     int reverse=0;
     int n;
        n=countDigit(x);
        int temp;
        while(n!=-1)
        {
           temp=x%10;
            cout<<temp;
            reverse=reverse+(temp*power(10,n));
            n--;
            x=x/10;
        }
        return reverse;
}

int main()
{
    cout<<"Enter number: ";
    int number;
    cin >>number;
   cout<<endl<<"Revverse is: "<<reversel(number);
   
    return 0;
}