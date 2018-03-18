/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void flatten1(TreeNode* A)
{
     if (A->left== NULL&&A->right==NULL)
    {
        return ;
    }
    else if(A->left==NULL)
    {
       flatten1(A->right);  
        
    }
    else if(A->right==NULL)
    {
        A->right=A->left;
        A->left=NULL;
        flatten1(A->right);
    }
    else
    {
        TreeNode* temp=A->right;
        TreeNode* preorder=A->left;
        A->right=A->left;
        A->left=NULL;
        
        while ( preorder->right)
        {
            preorder=preorder->right;
        }
        preorder->right=temp;
        flatten1(A->right);
    }
}
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   flatten1(A);
   return A;
}
