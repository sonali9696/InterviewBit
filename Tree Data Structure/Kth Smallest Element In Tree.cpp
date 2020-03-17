/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inOrder(TreeNode* A, int &ans, int &count, int k)
{
    if(A == NULL) return;
    
    inOrder(A->left, ans, count, k);
    count++;
    if(count == k)
    {
        ans = A->val;
        return;
    }
    inOrder(A->right, ans, count, k);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    
    if(A == NULL) return -1;
    
    int ans = -1;
    int count = 0;
    
    inOrder(A, ans, count, B);
    
    return ans;
}
