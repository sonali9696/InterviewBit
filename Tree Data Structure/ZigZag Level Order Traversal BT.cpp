/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    
    if(A == NULL) return ans;
    
    stack<TreeNode*> s1; //prints left to right
    stack<TreeNode*> s2; //prints right to left

    s1.push(A);
    
    vector<int> v;
    
    TreeNode* ptr;
        
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            ptr = s1.top();
            s1.pop();
            
            v.push_back(ptr->val);
            
            if(ptr->left != NULL) 
                s2.push(ptr->left);
                
            if(ptr->right != NULL) 
                s2.push(ptr->right);
        }
        
        if(!v.empty())
        {
            ans.push_back(v);
            v.clear();
        }
        
        while(!s2.empty())
        {
            ptr = s2.top();
            s2.pop();
            
            v.push_back(ptr->val);
            
            if(ptr->right != NULL)
                s1.push(ptr->right);
            if(ptr->left != NULL)
                s1.push(ptr->left);
        }
        
        if(!v.empty())
        {
            ans.push_back(v);
            v.clear();
        }
    }
    
    return ans;
}
