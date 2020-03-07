/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    
    if(A == NULL) return ans;
    
    queue<pair<TreeNode*,int> > q;
    q.push(make_pair(A,0));
    
    //vector<TreeNode*> visited; //stored all visited nodes 
    int curr_level = 0;
    vector<int> v;
    ans.push_back(v); //empty vector pushed to access it.
    
    while(!q.empty())
    {
        TreeNode* curr = q.front().first;
        int l = q.front().second;
        q.pop();
        
        //if(find(visited.begin(), visited.end(),curr) != visited.end())
        //    continue; //already visited
        
        //visited.push_back(curr);
        if(l > curr_level)
        {
            curr_level = l;
            ans.push_back(v);
        }
        ans[l].push_back(curr->val);
        
        if(curr->left != NULL)
        //&& (find(visited.begin(), visited.end(),curr->left) == visited.end())) 
        {
            q.push(make_pair(curr->left, l+1));
        }
        if(curr->right != NULL)
        //&& (find(visited.begin(), visited.end(),curr->right) == visited.end())) 
        {
            q.push(make_pair(curr->right, l+1));
        }
    }
    
    return ans;
    
}

