using namespace std;
#include<iostream>
#include<stack>
#include<string>
bool checkPalindrome(string str)
{
	int length=str.size();
	stack<char> s;
	int i;
	for(i=0;i<length/2;i++)
	{
		s.push(str[i]);
	}
	if(length%2!=0)
	{
		i++;
	}
	
	while(!s.empty())
	{
		char temp=s.top();
		if(temp!=str[i])
		{
			return false;
		}
		i++;
		s.pop();
	}
	return true;
}
int main()
{
	cout<<"Enter string: ";
	string str;
	getline(cin,str);
	if(checkPalindrome(str))
	{
		cout<<"\nGiven string is palindrome.";
	}
	else
	{
		cout<<"\nGiven string is not palindrome.";
	}
	return 0;
}
