/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    if(A == NULL && B == NULL) return 1;
    if(A == NULL && B != NULL) return 0;
    if(B == NULL && A != NULL) return 0;
    
    if(A->val == B->val && 
        isSameTree(A->left,B->left) == 1 &&
        isSameTree(A->right,B->right) == 1) return 1;
    else return 0;
    
}
