// this prog calculates maximum occuring character in a string.
// time  complexity : O(n)  linear time
// space complexity: O(1)  hash array is used.(fixed array) independent of input
#include <iostream>
#include<string>
using namespace std;
# define ASCII_SIZE 256// maximum characters 
void max_occur(string  string1)
{
	char result;
	int count;
	int hash[ASCII_SIZE]={0};
	for(int i=0;i<string1.length();i++)
	{
		hash[string1[i]]++;
	}
	int max=-1;
	for (int i=0;i<string1.length();i++)
	{
		if(max<hash[string1[i]])
		{
			max=hash[string1[i]];
			result=string1[i];
		}
	}
	cout<<"maximum occurring character in "<<string1<<" is '"<<result<<"' with a count of "<<max;

	return;
}

int main () 
{
	string str;
	cout<<"enter string:";
	//cout<<endl;
	getline(cin,str);
	max_occur(str);

	return 0;
}
//char max_occur(char* string1)
