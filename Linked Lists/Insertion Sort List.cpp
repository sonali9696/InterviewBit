/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
   
    //selection sort actually   
    ListNode* ptr1 = A;
    ListNode* ptr2 = A->next;
    ListNode* minN = NULL;
    
    while(ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        int min = ptr1->val;
        minN = ptr1;
        
        while(ptr2 != NULL)
        {
            if(ptr2->val < min)
            {
                min = ptr2->val;
                minN = ptr2;
            }
            ptr2 = ptr2->next;
        }
        
        int temp = ptr1->val;
        ptr1->val = minN->val;
        minN->val = temp;
        
        ptr1 = ptr1->next;
    }
    
    return A;
}
