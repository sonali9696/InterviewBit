/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    if(A == NULL || A->next == NULL) return A;
    if(m < 1 || m == n) return A;
    
    ListNode* p = NULL;
    ListNode* c = A;
    ListNode* np = c->next;
    
    int count = 1; //position of c
    
    while(count != m)
    {
        count++;
        p = c;
        c = np;
        np = np->next;
    }
    //todo: connect to tail
    ListNode *start = c;
    ListNode *head = p;
    
    if(p != NULL)
    {
        head->next = NULL;
        p = NULL; //separate the middle list
    }
    
    while(count != n+1 && c != NULL)
    {
        c->next = p;
        p = c;
        c = np;
        if(count == n)
        {
            if(head == NULL) A = p;
            else head->next = p; //head connected;
            break;
        }
        if(np->next != NULL)np = np->next;
        else
        {
            np->next = p;
            if(head != NULL)head->next = np; //connected to head
            else A = np;
            np = NULL;
            
            break;
        }
        
        count++;
    }
    
    start->next = np; //connected to tail
    
    return A;
}
