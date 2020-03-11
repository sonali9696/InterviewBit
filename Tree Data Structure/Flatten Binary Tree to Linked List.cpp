/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/* ANSWER 1
vector<int> ans;
 
void preorderT(TreeNode* root)
{
    if(root != NULL)
    {
        ans.push_back(root->val);
        preorderT(root->left);
        preorderT(root->right);
    }
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    
    ans.clear();
    
    preorderT(A);
    
    A->left = NULL;
    
    TreeNode* ptr;
    ptr = A;
    
    int i = 1;
    while(i != ans.size())
    {
        TreeNode* node = new TreeNode(ans[i]);
        ptr->right = node;
        ptr = node;
        i++;
    }
    
    return A;    
}*/

 
TreeNode* preorderT(TreeNode* root)
{
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL) return root;
    
    TreeNode *temp1 = preorderT(root->left);
    TreeNode *temp2;
    temp2 = preorderT(root->right);
    
    root->left = NULL;
    root->right = temp1;
    
    TreeNode *ptr = temp1;
    
    while(temp1 != NULL && ptr->right != NULL) ptr = ptr->right;
    if(temp1 != NULL)ptr->right = temp2;
    else root->right = temp2;
        
    return root;
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    A = preorderT(A);
    return A;    
}
