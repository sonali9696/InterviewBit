/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* A, ListNode* B)
{
    if(A == NULL) return B;
    else if(B == NULL) return A;
    
    //ListNode* ptr1 = A, ptr2 = B;
    ListNode* C = NULL;
    
    if(A -> val <= B -> val)
    {
        C = A;
        A = A->next;
    }
    else
    {
        C = B;
        B = B->next;
    }
    
    ListNode* ptr3 = C;
    
    while(A && B)
    {
        if(A -> val <= B -> val)
        {
            ptr3->next = A;
            ptr3 = ptr3->next;
            A = A->next;
        }
        else
        {
            ptr3->next = B;
            ptr3 = ptr3->next;
            B = B->next;
        }    
    }
    
    if(A)
    {
        ptr3->next = A;
    }
    
    if(B)
    {
       ptr3->next = B;
    }
    
    return C;
}

ListNode* mergeK(vector<ListNode*> &A, int beg, int end)
{
    int mid = (beg+end)/2;
    if(end > beg)
    {
        ListNode* P = mergeK(A, beg, mid);
        ListNode* Q = mergeK(A, mid + 1, end);
        ListNode* output = merge(P, Q);
        return output;
    }
    else return A[beg];
}
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int K = A.size();
    
    ListNode* ans = mergeK(A, 0, K-1);
    
    return ans;
}
 

