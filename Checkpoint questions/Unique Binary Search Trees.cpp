/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<TreeNode*> generate(int low, int high){
    
    vector<TreeNode*> curr_ans;
    
    if(low > high)
    {
        TreeNode* t = NULL;
        curr_ans.push_back(t);
        return curr_ans;
    }
    
    for(int i = low; i <= high; i++) //parent node
    {
        vector<TreeNode*> l = generate(low,i-1);
        vector<TreeNode*> r = generate(i+1,high);
        
        //construct all possible trees from above list of left and right subtrees
        for(int j=0; j<l.size(); j++)
        {
            for(int k=0; k<r.size(); k++)
            {
                TreeNode* node = new TreeNode(i);
                node->left = l[j];
                node->right = r[k];
                curr_ans.push_back(node);
            }
        }
        
        l.clear();
        r.clear();
    }
    
    return curr_ans;
    
}
 
vector<TreeNode*> Solution::generateTrees(int A) {
    vector<TreeNode*> ans;
    ans = generate(1,A);
    return ans;
}
