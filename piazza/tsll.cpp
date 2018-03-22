#include<iostream>
using namespace std;
#include<cstring>
template<class T> class SLinkedList ;
template<class T>
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
	  T elem; 
	  SNode<T>* next; 
	  friend class SLinkedList<T>; // provides SLinkedList access to SNode
};

template<class T>
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
	const T& front() const; 			// get front element
	void addFront(const T& e); 		// add to front of list
	void addBack(const T& e); 			// add to back of list
	void removeFront();			 			// remove from front 
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	SNode <T> *newNode(const T& e)
	{
		SNode<T> *temp=new SNode<T>();
		temp->next=NULL;
		temp->elem=e;
		return temp;
	}
	private:
	SNode<T> *head; 							// pointer to the head of list
};
template<class T>
bool SLinkedList<T>::empty() const
{
	return head==NULL;
}
template<class T>
const T& SLinkedList<T>::front() const
{
	return head->elem;
}
template<class T>
void SLinkedList<T>::addFront(const T& e)
{
	SNode<T> *node =newNode(e);
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
template<class T>
void SLinkedList<T>::addBack(const T& e)
{
	SNode<T> *node =newNode(e);
    if (head==NULL) {
        head=node;
    }
    else {
        SNode<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next; 
        }
        temp->next = node;
    }
    
}
template<class T>
void SLinkedList<T>::removeFront()
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
template<class T>
void SLinkedList<T>::removeEnd()
{
	SNode<T> *temp = head;
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
template<class T>
void SLinkedList<T>::print()
{
	SNode<T> *temp=head;
	cout<<"\n Linked list is: ";
	while(temp!=NULL)
	{
		cout<<temp->elem<<" ";
		temp=temp->next;
	}
}
int main()
{

	SLinkedList<int> obj;
    while(1) {
        cout << "\n1.Insert at front\n2.Insert at end\n3.Delete at begin\n4.delete at end\n5.display\n";
        int choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        int temp;
        switch(choice) {
            case 1 :    cout << "\nEnter New Element\t:\t";
                        cin>>temp;
                        obj.addFront(temp);
                        break;
            case 2 :    cout << "\nEnter New Element\t:\t";
                       cin>>temp;
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
