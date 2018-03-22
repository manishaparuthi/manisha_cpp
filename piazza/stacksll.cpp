#include<iostream>
using namespace std;
#include<cstring>
class SNode
{
	/*
	objective: Create a class for a Node for Single Linked list
	input parameters: none
	output value: none
	description: SNode class defines the node structure
	approach: Class defines data item is names element with datatype string
			and link is named next pf snode type
	*/
/*public:
	 SNode(string v)
	 {
            elem = v;
            next = NULL;
      }*/
	private:
	  int elem;
	  SNode* next;
	  friend class Stack; // provides SLinkedList access to SNode
};


class Stack
{
	/*
	objective: Create a Stack class
	input parameters: none
	output value: none
	side effects: Class Stack defines Single Linked LIst class
	approach: Class definition
	*/
	public:
	Stack()
	{
		head=NULL;
	}							// empty list constructor
	~Stack()
	{
		delete head;
	}							// destructor
	bool empty() const; 					// is list empty?
	const int& front() const; 			// get front element
	void push(const int& e); 		// add to front of list
	//void addBack(const string& e); 			// add to back of list
	void pop();			 			// remove from front
	//void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	SNode* newNode(const int& e)
	{
		SNode* temp=new SNode();
		temp->next=NULL;
		temp->elem=e;
		return temp;
	}
	private:
	SNode* head; 							// pointer to the head of list
};
bool Stack::empty() const
{
	return head==NULL;
}
const int& Stack::front() const
{
	return head->elem;
}
void Stack::push(const int& e)
{
	SNode* node =newNode(e);
	if(head==NULL)
	{
		head=node;
	}
	else
	{
		node->next=head;
		head=node;
	}		//SNode* node =new SNode(e);

}
/*void Stack::addBack(const string& e)
{
	SNode* node =newNode(e);
    if (head==NULL) {
        head=node;
    }
    else {
        SNode *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }

}
*/
void Stack::pop()
{
	if(head->next==NULL)
	{
		head=NULL;
	}
	else if(!empty())
	{
		head=head->next;
	}

}
/*void SLinkedList::removeEnd()
{
	SNode *temp = head;
	if(head->next==NULL)
	{
		head=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
	}
	delete temp;
}
*/
void Stack::print()
{
	SNode* temp=head;
	cout<<"\n Stack is: ";
	while(temp!=NULL)
	{
		cout<<temp->elem<<" ";
		temp=temp->next;
	}
}
int main()
{

	Stack obj;
    while(1) {
        cout << "\n1.Push\n2.Pop\n3.Top element\n4.Display\n5.Exit\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        int temp;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        cin>>temp;
                        obj.push(temp);
                        break;
            case 2 :    obj.pop();
                        break;
            case 3 :    if(obj.empty())
            			{
                            cout << "\nStack is Empty.\n";
                        }
                        else
                        {
                           temp=obj.front();
                           cout<<"Element at the top is: "<<temp;
                        }
                        break;
            case 4 :    if(obj.empty())
            			{
                            cout << "\nStack is Empty.\n";
                        }
                        else
                        {
                            obj.print();
                        }
                        break;
            case 5 :    exit(0);
                        break;
            default:    cout << "\nInvalid Input\n";
        }
    }
    return 0;
}
