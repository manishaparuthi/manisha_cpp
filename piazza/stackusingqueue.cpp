using namespace std;
#include<iostream>
#include<queue>
class stack
{
	queue<int> q1,q2;
	public:
	void push(int);
	void pop();
	bool empty();
	int peek();
	int size();
	void display();
};

void stack:: push(int a)
{
	q2.push(a);
	
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
			
		}
		queue<int> q3;
		q3=q1;
		q1=q2;
		q2=q3;
		
	
}
void stack:: pop()
{
	cout<<"element returned is: "<<q1.front();
	q1.pop();	
} 
int stack:: peek()
{
	return q1.front();
 } 
 bool stack:: empty()
 {
 	return(q1.empty());
  } 
int stack:: size()
{
	return (q1.size());
 } 
 void stack::display()
 {
 	q2=q1;
 	cout<<"\n stack is : ";
	 while(!q2.empty())
 	{
 		cout<<q2.front()<<" ";
 		q2.pop();
	 }
 }
 int main()
 {
 	stack obj;
    while(1) {
        cout << "\n\n1.push\n\n2.pop\n\n3.top\n\n4 size\n\n 5.display\n\n6.Exit\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        int temp;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        cin >> temp;
                        obj.push(temp);
                        break;
            case 2 :    if(obj.empty())
            			{
							cout << "\nstack is Empty.\n";
                        }
                        else 
                        {
                            obj.pop();
                            obj.display();
                        }
                        break;
            case 3 :    if(obj.empty())
						 {
                            cout << "\nstack is Empty.\n";
                        }
                        else {
                        	temp=obj.peek();
				            cout << "\ntop of stack\t:\t" << temp;
                        }
                        break;
            case 4 :    cout << "\nSize of stack\t:\t" << obj.size();
                        break;
            case 5 :    if(obj.empty())
						{
							cout<<"stack is empty ";
						}				
						else
						{
						   obj.display();
					    }
            			break;
            case 6 :    exit(0);
                        break;
            default:    cout << "\nInvalid Input\n";
        }
    }
 }
