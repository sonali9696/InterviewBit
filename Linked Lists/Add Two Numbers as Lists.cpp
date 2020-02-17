/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry = 0;
    
    ListNode* h1 = A;
    ListNode* h2 = B;
    
    if(h1 == NULL && h2 == NULL) return NULL;
    if(h1 == NULL || h1->val == 0) return h2;
    else if(h2 == NULL || h2->val == 0) return h1;
    
    ListNode* ans = new ListNode(0);
    ListNode *head;
    
    int num, flag = 0;
    
    while(h1 != NULL && h2 != NULL)
    {
        num = h1->val + h2->val + carry;
        if(flag == 0)
        {
            carry = num/10;
            ans->val = num % 10;
            flag = 1;
            head = ans;
        }
        else
        {
            ListNode* node = new ListNode(0);
            ans->next = node;
            carry = num/10;
            node->val = num % 10;
            ans = node;
        }
        ans->next = NULL;
        h1 = h1->next;
        h2 = h2->next;    
    }

    
    ListNode* remH;
    
    if(h1 == NULL) remH = h2;
    else if(h2 == NULL) remH = h1;//one list left
    else remH = NULL;
    
    while(remH != NULL)
    {
        ListNode* node = new ListNode(0);
        ans->next = node;
        num = remH->val + carry;
        carry = num/10;
        node->val = num % 10;
        ans = node;
        ans->next = NULL;
        remH = remH->next;
    }
    
    //digits left
    while(carry != 0)
    {
        ListNode* node = new ListNode(0);
        ans->next = node;
        ans = node;
        ans->next = NULL;
        node->val = carry % 10;
        carry /= 10;
    }
    
    return head;
}
