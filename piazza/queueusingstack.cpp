using namespace std;
#include<iostream>
#include<stack>
class queue
{
	stack<int> s1,s2;
	public:
	void enqueue(int);
	void dequeue();
	bool empty();
	int peek();
	int size();
	void display();
};

void queue:: enqueue(int a)
{
	if(s1.empty())
	{
		s1.push(a);
	}
	else
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(a);
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
}
void queue:: dequeue()
{
	cout<<"element returned is: "<<s1.top();
	s1.pop();	
} 
int queue:: peek()
{
	return s1.top();
 } 
 bool queue:: empty()
 {
 	return(s1.empty());
  } 
int queue:: size()
{
	return (s1.size());
 } 
 void queue::display()
 {
 	s2=s1;
 	cout<<"\n Queue is : ";
	 while(!s2.empty())
 	{
 		cout<<s2.top()<<" ";
 		s2.pop();
	 }
 }
 int main()
 {
 	queue obj;
    while(1) {
        cout << "\n\n1.enqueue\n\n2.dequeue\n\n3.front\n\n4 size\n\n 5.display\n\n6.Exit\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        int temp;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        cin >> temp;
                        obj.enqueue(temp);
                        break;
            case 2 :    if(obj.empty())
            			{
							cout << "\nqueue is Empty.\n";
                        }
                        else 
                        {
                            obj.dequeue();
                            obj.display();
                        }
                        break;
            case 3 :    if(obj.empty())
						 {
                            cout << "\nqueue is Empty.\n";
                        }
                        else {
                        	temp=obj.peek();
				            cout << "\nfront of queue\t:\t" << temp;
                        }
                        break;
            case 4 :    cout << "\nSize of queue\t:\t" << obj.size();
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
