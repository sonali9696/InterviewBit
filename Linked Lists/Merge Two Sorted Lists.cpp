/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *h1 = A;
    ListNode *h2 = B;
    
    if(h1 == NULL && h2 == NULL) return NULL;
    else if(h1 == NULL) return h2;
    else if(h2 == NULL) return h1;
    
    ListNode *head = new ListNode(0);
    if(h1->val <= h2->val)
    {
        head->val = h1->val;
        h1 = h1->next;
    }
    else
    {
        head->val = h2->val;
        h2 = h2->next;
    }
    
    head->next = NULL;
    ListNode *ptr = head;
    
    while(h1 != NULL && h2 != NULL)
    {
        if(h1->val <= h2->val)
        {
            ListNode *node = new ListNode(0);
            node->val = h1->val;
            ptr->next = node;
            ptr = node;
            h1 = h1->next;
            node->next = NULL;
        }
        else
        {
            ListNode *node = new ListNode(0);
            node->val = h2->val;
            ptr->next = node;
            ptr = node;
            h2 = h2->next;
            node->next = NULL;
        }
    }
    
    //if any 1 list left
    ListNode *remH;
    if(h1 != NULL) remH = h1;
    else if(h2 != NULL) remH = h2;
    else //both list over
    {
        return head;
    }
    
    while(remH != NULL)
    {
        ListNode *node = new ListNode(0);
        node->val = remH->val;
        node->next = NULL;
        ptr->next = node;
        ptr = node;
        remH = remH->next;
    }
    
    return head;
}
