

#include<iostream>
#include<stack>
#include<string>

using namespace std;


bool isOperator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		return true;
	else
		return false;
}

int precedence(char opr)
{
	 
	if(opr == '+' || opr == '-')
		return 1;
	if(opr == '*' || opr == '/')
		return 2;
	if(opr == '^')
		return 3;
} 


void convertToPostFix(string expr){
	
	stack<char> s;
	int length=expr.size();
	for(int i=0;i<length;i++)
	{
		char opr = expr.at(i);
		if( opr == '(')
		{
			s.push('(');
		}
		else if( opr == ')')
		{
			while( !s.empty() && s.top()!='('){
				cout<<s.top()<<" ";
				s.pop();
			}
			s.pop();	
		}
		else if(!isOperator(opr)){
			cout<<opr<<" ";
		}
		else{
			if( s.empty() )
				s.push(opr);	
			else if(  precedence(opr) > precedence(s.top()) )
				s.push(opr);
			else{
				while( !s.empty() && s.top()!='(' && precedence(opr) <= precedence(s.top()) ){
					cout<<s.top()<<" ";
					s.pop();
				}
				s.push(opr);
			}
		}
	}
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}

int main()
{
	string exppr;
	cout<<"\nEnter expression: ";
	getline(cin,exppr);
	convertToPostFix(exppr);
	return 0;
}
