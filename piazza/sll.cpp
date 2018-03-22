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
	  string elem;
	  SNode* next;
	  friend class SLinkedList; // provides SLinkedList access to SNode
};


class SLinkedList
{
	/*
	objective: Create a Single LInked List class
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/
	public:
	SLinkedList()
	{
		head=NULL;
	}							// empty list constructor
	~SLinkedList()
	{
		delete head;
	}							// destructor
	bool empty() const; 					// is list empty?
	const string& front() const; 			// get front element
	void addFront(const string& e); 		// add to front of list
	void addBack(const string& e); 			// add to back of list
	void removeFront();			 			// remove from front
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	SNode* newNode(const string& e)
	{
		SNode* temp=new SNode();
		temp->next=NULL;
		temp->elem=e;
		return temp;
	}
	private:
	SNode* head; 							// pointer to the head of list
};
bool SLinkedList::empty() const
{
	return head==NULL;
}
const string& SLinkedList::front() const
{
	return head->elem;
}
void SLinkedList::addFront(const string& e)
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
void SLinkedList::addBack(const string& e)
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
void SLinkedList::removeFront()
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
void SLinkedList::removeEnd()
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
void SLinkedList::print()
{
	SNode* temp=head;
	cout<<"\n Linked list is: ";
	while(temp!=NULL)
	{
		cout<<temp->elem<<" ";
		temp=temp->next;
	}
}
int main()
{

	SLinkedList obj;
    while(1) {
        cout << "\n1.Insert at front\n2.Insert at end\n3.Delete at begin\n4.delete at end\n5.display\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        string temp;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        getline(cin,temp);
                        obj.addFront(temp);
                        break;
            case 2 :    cout << "\nEnter New Element\t:\t";
                        getline(cin,temp);
                        obj.addBack(temp);
                        break;
            case 3 :    if(obj.empty())
            			{
                            cout << "\nLinked List is Empty.\n";
                        }
                        else
                        {
                            obj.removeFront();
                        }
                        break;
            case 4 :    if(obj.empty())
            			{
                            cout << "\nLinked List is Empty.\n";
                        }
                        else
                        {
                            obj.removeEnd();
                        }
                        break;
            case 5:		if(obj.empty())
            			{
            				cout << "\nLinked List is Empty.\n";
            			}
            			else
            			{
            				obj.print();
            			}
            			break;
            case 6 :    exit(0);
                        break;
            default:    cout << "\nInvalid Input\n";
        }
    }
    return 0;
}
