using namespace std;
#include<iostream>

struct node {
    /*
    Objective : To create a node structure
    Structute Paramtrs:
      data  : integer type
      left  : pointer to left node
      right : pointer to right node
    */
    int data;
    node *left,*right;
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

void inorder( node *node ) {
    /*
    Objective : To print inorder traversal of the BST
    Input Paramtrs:
        node : initially root node
    Approach : Print according to order
              Left Root Right
    */
    if ( node == NULL )
        return;
    
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
} 

void preorder( node *node ) {
    /*
    Objective : To print preorder traversal of the BST
    Input Paramtrs:
        node : initially root node
    Approach : Print according to order
              Root Left Right
    */

    if ( node == NULL )
        return ;
    
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
} 

void postorder(node *node) {    
    /*
    Objective : To print postorder traversal of the BST
    Input Paramtrs:
        node : initially root node
    Approach : Print according to order
              Left Right Root 
    */
  
    if( node == NULL )
        return;
    
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main() {
    /*
    Objective : To perform different Traversal operations
    Approach: Display using inorder(), postorder() and preorder()
    */
    node *root = NULL;
    char ans;
    do {
        
        cout<<"\n MENU : \n 1. Insert an element \n 2. Print Inorder \n 3. Print Preorder \n 4. Print Postorder ";
        cout<<"\n Enter your choice : ";
        int ch;
        cin>>ch;
        
        switch(ch) {
            
            case 1: int el;
                    cout<<"\n Enter element to be inserted : ";
                    cin>>el;
                    if( root == NULL )
                        root = insertion(root,el);
                    else
                        insertion(root,el);
                    break;
                    
            case 2: cout<<"\n The status of the tree (Inorder) : ";
                    inorder(root);
                    break;
            
            case 3: cout<<"\n The status of the tree (Preorder) : ";
                    preorder(root);
                    break;
                    
            case 4: cout<<"\n The status of the tree (Postorder) : ";
                    postorder(root);
                    break;
        }
        
        cout<<"\n Do you want to continue(Y/N) : ";
        cin>>ans;
    }while(ans == 'Y' || ans == 'y');
   return 0; 
}
