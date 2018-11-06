using namespace std;
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
bool check_subsequence(vector<string> A,vector<string> B)
{
    int m=A.size();
    int n=B.size();
    if(m<n)
        return false;
    int i=0;
    int j=0;
    while(i<m&&j<n)
    {
        if(!B[j].compare(A[i]))
        {
            i++;
            j++;
        }
        else
        i++;
    }
    if (j==n)
    {
        return 1;
    }
    else
    return 0;
}
int main()
{
    vector<string> a;
    vector<string> b;
    cout<<"Events A reading from file......";
    string atemp;;
    ifstream eventAfile;
    eventAfile.open("eventsA.txt");
    while (std::getline(eventAfile, atemp))
    {
        a.push_back(atemp);
    }
    eventAfile.close();
   /* bool acontinue=true;
    do
    {
        string atemp;
        getline(cin,atemp);
        if(!atemp.compare("exit"))
        {
            acontinue=false;
        }
        else
            a.push_back(atemp);
    }while(acontinue);
   
    cout<<"Enter events B:";
    bool bcontinue=true;
    do
    {
        string btemp;
        getline(cin,btemp);
        if(!btemp.compare("exit"))
        {
            bcontinue=false;
        }
        else
            b.push_back(btemp);
    }while(bcontinue);
   */
    cout<<"Events B reading from file......";
    string btemp;;
    ifstream eventBfile;
    eventBfile.open("eventsB.txt");
    while (std::getline(eventBfile, btemp))
    {
        b.push_back(btemp);
    }
    eventBfile.close();
    if(check_subsequence(a,b))
    cout<<"\nyes,list of events b is a subsequence of events b";
    else
    cout<<"\nno, this is not a subsequence of event b";
    cout<<endl;
    return 0;
}
