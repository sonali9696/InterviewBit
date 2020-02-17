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
    
    if(head->next->val == head->val) //todo: find distinct head
    {
       while(head != NULL)  
       {
           
        if(head->next->val == head->val) //1 1 1 1 ... 2
        {
            head = head->next;
            if(head->next == NULL) return NULL; //no distinct head in entire list
        }
        else //1 1 1 1 2..
        {
            head = head->next;
            if(head->next == NULL || head->next->val != head->val) 
                break; //1 1 1 1 2 3 ..   not 1 1 1 1 2 2 2 3 ..
        }
       }    
    }
    
    if(head == NULL || head->next == NULL) return head;
    
    ListNode *cur = head->next;
    ListNode *prev = head; //prev always stores the last distinct value
    
    while(cur != NULL)
    {
        if(cur->next == NULL) break;
        
        if(cur ->next->val != cur->val)//1 2 3
        {
            prev = cur;
            cur = cur->next;
        }
        else //1 2 2 2 3 ..
        {
            int num;
            while(cur != NULL && cur->next != NULL)//.... 2 3 3 3
            {
                num = cur->val;
                prev->next = cur->next;
                cur = cur->next;
                if(cur->val == num) continue;
                else break;
            }
            
            if(cur == NULL) break;
            if(cur->next == NULL)
            {
                if(cur->val == num)
                {
                    prev->next = NULL;
                    break;
                }
            }
            
        }
    }
    
    return head;
}
