/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode* populate(int start, int end, vector<ListNode*> &list)
{
    if(start > end) return NULL;
    
    int mid = (start + end)/2;
    
    TreeNode* curr = new TreeNode(list[mid]->val);
    
    curr->left = populate(start, mid-1, list);
    curr->right = populate(mid+1, end, list);
    
    return curr;
}
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    
    vector<ListNode*> list;
    
    ListNode* ptr = A;
    while(ptr != NULL)
    {
        list.push_back(ptr);
        ptr = ptr->next;
    }
    
    int l = list.size();
    TreeNode* root = NULL;
    TreeNode* curr = root;
    
    if(l == 0) return root;
    
    int mid = (l-1)/2;
    
    curr = new TreeNode(list[mid]->val);
    root = curr;
    
    if(l == 1) return root;
    
    root->left = populate(0, mid-1, list);
    root->right = populate(mid+1, l-1, list);
    
    return root;
}

