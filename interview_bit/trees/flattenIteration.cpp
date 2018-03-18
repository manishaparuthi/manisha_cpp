using namespace std;
#include <iostream>
#include <queue>
struct node
{
    int data;
    struct node *left, *right;
};
 

struct node* flatten(struct node *root)
{ 
    struct node* temp=root;
    if(root==NULL)
    {
        return root;
    }
    else
    {
        while(temp)
        {
            if(temp->left)
            {
                struct node* temp1=temp->right;
                struct node* preorder=temp->left;
                while(preorder->right)
                {
                    preorder=preorder->right;
                }
                preorder->right=temp1;
                temp->right=temp->left;
                temp->left=NULL;

            }
            temp=temp->right;
        }
    }
    return root;
}
       
    


struct node* newNode(int data)//constructor
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(3);
    root->left->right = newNode(4);
    root->right->left  = newNode(6);
    //root->right->right = newNode(7);
    cout << "Flattening:  \n";
    struct node* result=flatten(root);
    while(result)
    {
        cout<<result->data<<" ";
        result=result->right;
    }
    return 0;
}
