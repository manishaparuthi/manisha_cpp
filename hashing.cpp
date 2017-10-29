#include <iostream>
#include<string>
using namespace std;
# define ASCII_SIZE 256
int main()
{
	int hash[ASCII_SIZE]={0};
	string str;
	cout<<"enter string:";
	getline(cin,str);
	for(int i=0;i<str.length();i++)
	{
		hash[str[i]]++;
	}
	for(int i=0;i<str.length();i++)
	{
		cout<<"count of '"<<str[i]<<"' is "<<hash[str[i]]<<endl;
	}
	
	return 0;
}