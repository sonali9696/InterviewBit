/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode* ptr, map<TreeNode*, int> &h, int &ans)
{
    if(ptr == NULL) 
        return -1;
    
    if(ptr->left == NULL && ptr->right == NULL) //leaf
    {
        h[ptr] = 0;
        return 0;
    }
    
    if(h.find(ptr) != h.end()) return h[ptr];
    
    int l = height(ptr->left, h, ans);
    int r = height(ptr->right, h, ans);
    
    int val = abs(l - r);
    if(val > 1) ans = 0; //need to check height of EACH node
    
    if(l >= r) h[ptr] = l + 1;
    else h[ptr] = r + 1;
    
    return h[ptr];
}
 
int Solution::isBalanced(TreeNode* A) {
    
    if(A == NULL) return 1;
    
    map<TreeNode*, int> h; //height of node
    int ans = -1;
    
    int diff = abs(height(A->left, h, ans) - height(A->right, h, ans));
    if(diff <= 1 && ans != 0) return 1;
    else return 0;
}
