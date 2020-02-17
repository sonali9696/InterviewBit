/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *p1 = A;
    ListNode *p2 = A->next->next;
        
    //if cycle found, since pos + cycle size = pos
    //thus find cycle size, take 2 ptr separated by cycle size, and move one by one
    //they will meet at starting point as distance between them should always be = cycle size
    //which will make them overlap
    
    int found = 0;
    
    while(p1 != NULL && p2 != NULL)
    {
        if(p1 == p2)
        {
            found = 1;
            break;
        }
        p1 = p1->next;
        
        if(p2->next != NULL) p2 = p2->next->next;
        else p2 = NULL;
        
        
    }
    
    if(p1 == NULL || p2 == NULL || found == 0) //not found
        return NULL;
    
    //count size of cycle
    int count = 1;
    while(p1->next != p2)
    {
        p1 = p1->next;
        count++;
    }
    
    p1 = A;
    
    //p2 is count away from A
    p2 = A;
    int c = 0;
    while(c != count)
    {
        p2 = p2->next;
        c++;
    }
    
    //start pos
    while(p1 != p2)
    {
        p2 = p2->next;
        p1 = p1->next;
    }
    
    return p1;
}
