using namespace std;
#include<iostream>
#include<stack>
#include<string>
#include<queue>
bool checkPalindrome(string str)
{
	int length=str.size();
	stack<char> s;
	queue<char> q;
	int i;
	for(i=0;i<length/2;i++)
	{
		s.push(str[i]);
	}
	int k;
	if(length%2!=0)
	{
		k=i+1;
		for(int i=k;i<length;i++)
		{
		    q.push(str[i]);
		}
	}
	else
	{
	    k=i;
	    for(int i=k;i<length;i++)
		{
		    q.push(str[i]);
		}
	}
	
	while(!s.empty()&&!q.empty())
	{
	
		if(s.top()!=q.front())
		{
			return false;
		}
	    q.pop();
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
