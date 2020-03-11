/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
     //base case
    if(postorder.size() == 0 || inorder.size() == 0) return NULL;
    
    TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
    vector<int> leftIn;
    vector<int> rightIn;
    vector<int> leftP;
    vector<int> rightP;
    
    int i=0, j = 0;
    while(i < inorder.size() && inorder[i] != root->val)
    {
        leftIn.push_back(inorder[i]);
        leftP.push_back(postorder[j]);
        i++;
        j++;
    }
    
    i++; //right
    
    while(i < inorder.size())
    {
        rightIn.push_back(inorder[i]);
        rightP.push_back(postorder[j]);
        i++;
        j++;
    }
    
    root->left = buildTree(leftIn, leftP);
    root->right = buildTree(rightIn, rightP);
    
    return root;
}
