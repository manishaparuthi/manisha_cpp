

using namespace std;
#include<string>
#include<iostream>
bool check_subsequence(string A,string B)
{
    int m=A.size();
    int n=B.size();
    int i=0;
    int j=0;
    while(i<m&&j<n)
    {
        if(A[i]==B[j])
        {
            i++;
            j++;
        }
        else
        j++;
    }
    if (i==m)
    {
        return 1;
    }
    else
    return 0;
}
int main()
{
    string a,b;
    cout<<"enter String A:";
    getline(cin,a);
    cout<<"enter string B:";
    getline(cin,b);
    if(check_subsequence(a,b))
    cout<<"yes";
    else
    cout<<"no";

    return 0;
}
