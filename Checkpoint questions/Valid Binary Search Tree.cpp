/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool check(TreeNode* root, TreeNode* ptr)
{
    TreeNode* p = root;
    while(p != ptr && p != NULL)
    {
        if(ptr->val < p->val) p = p->left;
        else if(ptr->val > p->val) p = p->right;
        else if(ptr->val == p->val && ptr != p) return 0;
    }
    
    if(p == NULL) return 0;
    if(p == ptr) return 1;
}

bool isValid(TreeNode* root, TreeNode* ptr)
{
    if(ptr == NULL) return 1;
    int valid = check(root, ptr);
    
    if(valid == 0) return 0;
    
    int ans1 = isValid(root, ptr->left);
    int ans2 = isValid(root, ptr->right);
    
    if(ans1 == 1 && ans2 == 1) return 1;
    else return 0;
}
 
int Solution::isValidBST(TreeNode* A) {
    return isValid(A, A);
}
