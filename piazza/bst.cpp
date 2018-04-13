using namespace std;
#include<iostream>
#include<queue>

struct node {
    /*
    Objective : To create a node structure
    Structute Paramtrs:
      data  : integer type
      left  : pointer to left node
      right : pointer to right node
    */
    
    int data;
    node *left;
    node *right;
};

node *create_node(int data) {
     /*
    Objective : To create a new node with its data element, left and right pointer
    Input Parmtrs:
      data : value of the node to be added
    Return Value:
      temp : node of structure type is created and returned
    */
    
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *insertion(node *node,int data) {
    /*
    Objective : To insert a node in Binary Search Tree
    Input Parmters:
        *node : initially points to root node
        data : data of the new node to be added
     Return Value:
        return currently added 'node'
     Approach: 
        if root's value is greater than the new node to be added then move root's left
        otherwise, move root's right
    */
    
    if ( node == NULL) {
        return create_node(data);
    }
    
    else if ( node->data <= data ) {
        node->right = insertion(node->right,data);
    }
    
    else 
        node->left = insertion(node->left,data);
    
    return node;
}

void display(node* Node) {
    /*
    Objective : To display the current status of the Binary Search Tree
    Input Parmters :
        Node : Initially pointed to root 
    Approach : Print the binary searchh tree level by level
    */
    
    if ( Node == NULL )
        return ;
    
    queue<node*> q;
    q.push(Node);
    
    while(!q.empty()) {
        node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if ( temp->left )
            q.push(temp->left);
        if ( temp->right )
            q.push(temp->right);
    }
}

node *min_node(node *Node) {
    node *temp = Node;
    while( temp->left != NULL )
        temp = temp->left;
    return temp;
}

node *deletion(node *Node,int data) {
    
    /*
    Objective : To delete a node from BST
    Input Parmters:
        Node : Initially root
        data : data of the node to be deleted
    Approach :
        First find the node to be deleted in the tree
        if node's either left or right child is NULL, then node is 
            node's right or left respectively
        otherwise find the node's predecessor and replace it with the 
            node's data...and delete node's predecessor.
    */
    
    if ( Node == NULL ) {
        cout<<"\n There is no such node in the tree to delete.";
    
    }
    else if ( Node->data < data ) 
        Node->right = deletion(Node->right,data);
    
    else if ( Node->data > data )
        Node->left = deletion(Node->left,data);
    
    else {
        if (Node->left == NULL )
        {
            node *temp = Node->right;
            delete Node;
            return temp;
        }
        else if ( Node->right == NULL )
        {
            node *temp = Node->left;
            delete Node;
            return temp;
        }
        node *temp = NULL;
        temp = min_node(Node->right);
        Node->data = temp->data;
        Node->right = deletion(Node->right,temp->data);
        
    }
    return Node;
}


int main() {
    /*
    Objective : To perform different Traversal operations
    Approach  : perform using insertion(), display() and detetion()
    */
    char ans;
    int el;
    node *root = NULL;
    do {
        cout<<"\n MENU : \n 1. Insert an element \n 2. Display the status \n 3. Delete a node";
        int ch;
        cout<<"\n Enter your choice : ";
        cin>>ch;
        
        switch(ch) {
            
            case 1: cout<<"\n Enter element to be inserted : ";
                    cin>>el;
                    if( root == NULL )
                        root = insertion(root,el);
                    else
                        insertion(root,el);
                    break;
            
            case 2: cout<<"\n The status of the binary tree is : ";
                    display(root);
                    break;
                    
            case 3: cout<<"\n Enter an element you want to delete : ";
                    cin>>el;
                    root = deletion(root,el);
                    break;
        }
        
        cout<<"\n Do you want to continue (Y/N) : ";
        cin>>ans;
    }while(ans == 'Y' || ans == 'y');
    
    return 0;
}
