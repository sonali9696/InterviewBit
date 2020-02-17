int Solution::removeDuplicates(vector<int> &A) {
    
    if(A.size() <= 1) return A.size();
    
    int curr = 1;
    
    for(int i = 1 ; i < A.size(); i++)
    {
        if(A[i] == A[i-1]) 
        {
            /*A.erase(A.begin() + i, A.begin() + i + 1); 
            i--; //since the new should be the same position after i++ in for loop
            */
            
            //bring elements to front without actually removing
            continue;
        }
        else
        {
            A[curr] = A[i];
            curr++;
        }
    }
    
    return curr;
    
}
