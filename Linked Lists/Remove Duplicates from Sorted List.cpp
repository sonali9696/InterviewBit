/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode* head = A;
    if(head == NULL || head->next == NULL) return A;
    
    ListNode *prev = A;
    ListNode *cur = A->next;
    
    while(cur->next != NULL)
    {
        if(cur->val == prev->val) //delete curr
        {
            prev->next = cur->next;
            cur = cur->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    
    //cur is the last node now
    if(cur->val == prev->val) //delete curr
    {
        prev->next = NULL;
        cur = prev;
    }
    
    return head;
    
}
