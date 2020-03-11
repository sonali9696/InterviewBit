/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int flag = 0;

void sumT(TreeNode* A, int tot, int curr)
{
    //base case
    if(A->left == NULL && A->right == NULL)
    {
        if(curr + A->val == tot) flag = 1;
        return;
    }
    
    if(A->left != NULL) sumT(A->left, tot, curr + A->val);
    if(A->right != NULL) sumT(A->right, tot, curr + A->val);
}
 
int Solution::hasPathSum(TreeNode* A, int B) {
    flag = 0;
    
    if(A->left != NULL) sumT(A->left, B, A->val);
    if(A->right != NULL) sumT(A->right, B, A->val);
    
    if(A->left == NULL && A->right == NULL) //only root, no children
    {
        if(A->val == B) return 1;
        else return 0;
    }
    
    return flag;
}
