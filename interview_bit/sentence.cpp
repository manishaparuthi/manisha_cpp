using namespace std;
#include <iostream>
#include<string>
int findnextspace(int prev,string &A)
{
    for(int i=prev+1;i<A.size();i++)
    {
        if(isspace(A[i]))
        {
            return i;
        }
    }
}


void swap(char &a,char &b)
{
    char temp=a;
    a=b;
    b=temp;
}


void reverseword(int i,int j ,string&A)
{
    int k=0;
    for(int x=i; x<=(i+j)/2;x++)
    {
    	//cout<<endl<<"swapping "<<A[x]<<" and "<<A[j-k];
        swap(A[x],A[j-k]);
        k++;
    }
}
void reverseWords(string &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int totalspace=0;
    for(int i=0;i<A.size();i++)
    {
        if(isspace(A[i]))
        {
            totalspace++;
        }
    }
    //cout<<"totalspace: "<<totalspace;
     int init=-1;
    int fin=0;
    int i=0;
    while(i<totalspace)
    {
        //cout<<endl<<"init: "<<init;
        fin=findnextspace(init,A);
       // cout<<endl<<"fin: "<<fin;
       // cout<<endl<<"reversing between "<<init+1<<"and "<<fin-1;
        reverseword(init+1,fin-1, A);
       // cout<<endl<<"string: "<<A;
       // init=findnextspace(fin,A);
       init=fin;
        i++;
    }
    fin=A.size();
    reverseword(init+1,fin-1,A);
   reverseword(0,A.size()-1, A);
}
int main()
{
	string test;
	cout<<"Enter sentence: ";
	getline(cin,test);
	reverseWords(test) ;
	//cout<<endl;
	cout<<"test: "<<test;
	return 0;

}

