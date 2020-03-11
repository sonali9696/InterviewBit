/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    //base case
    if(preorder.size() == 0 || inorder.size() == 0) return NULL;
    
    TreeNode* root = new TreeNode(preorder[0]);
    vector<int> leftIn;
    vector<int> rightIn;
    vector<int> leftPre;
    vector<int> rightPre;
    
    int i=0, j = 1;
    while(i < inorder.size() && inorder[i] != root->val)
    {
        leftIn.push_back(inorder[i]);
        leftPre.push_back(preorder[j]);
        i++;
        j++;
    }
    
    i++; //right
    while(i < inorder.size())
    {
        rightIn.push_back(inorder[i]);
        rightPre.push_back(preorder[j]);
        i++;
        j++;
    }
    
    root->left = buildTree(leftPre, leftIn);
    root->right = buildTree(rightPre, rightIn);
    
    return root;
    
}
