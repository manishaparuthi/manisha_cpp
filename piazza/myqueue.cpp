#include<iostream>
using namespace std;
class myqueue
{
	int *queue;
	int cap;
	int front;
	int rear;
	public:
		
	void insert();
	void del();
	void display();
	myqueue()
	{
		int c;
		cout<<"Enter the capacity";
		cin>>c;
		cap=c;
		queue= new int[c];
		//queue= NULL;
		front=rear=-1;
	}
	~myqueue()
	{
		delete (queue);
	}
	void isEmpty()
	{
		if(front==-1 && rear == -1)
			cout<<"queus is empty"<<endl;
		else
			cout<<"Queue is non- empty"<<endl;
	}
	void isFull()
	{
		if (rear==cap-1)
			cout<<"Queue is full"<<endl;
		else
			cout<<"Queue is not full"<<endl;
	}
	void countEl()
	{
		int count=0;
		if(front==-1 && rear== -1)
		{
			cout<<"total elements is zero"<<endl;
		}
		for(int i=front;i<=rear;i++)
			count++;
		cout<<"Total elemnts are "<<count<<endl;
	}
};
void myqueue:: insert()
{
	int val;
	if (rear==cap-1)
		cout<<"The queue is full"<<endl;
	else
	{
		cout<<"Enter the value you want to insert"<<endl;
		cin>>val;
		if(rear==-1 && front==-1)
		{
			rear++;
			front++;
		}
		else
		{
			rear++;
		
		}
		queue[rear]=val;
	}
}
void myqueue::del()
{
	if(front==-1 && rear==-1)
		cout<<"The queue is empty"<<endl;
	else
	{
		cout<<endl<<"deleted element is "<<queue[front]<<endl;
		front++;
	}
}
void myqueue::display()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<queue[i]<<endl;
		}
	}
}
int main()
{
	myqueue ob;
	int choice=1;
	int ch;
	while(choice==1)
	{
		cout<<"Enter your choice: "<<endl<<"1- insert"<<endl<<"2- delete"<<endl<<"3- display"<<endl<<"4- check full"<<endl<<"5- check empty"<<endl<<"6- Total element"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				ob.insert();
				break;
			case 2:
				ob.del();
				break;
			case 3: 
				ob.display();
				break;
				case 4:
					ob.isFull();
					break;
			case 5:
				ob.isEmpty();
				break;
			case 6:
				ob.countEl();
				break;
			default:
				cout<<"hmm! enter valid choice"<<endl;
		}
		cout<<"Do you want to continue( 1 for yes and 0 for no)"<<endl;
		cin>>choice;
	}
	return 0;
}
