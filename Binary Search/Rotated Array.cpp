int Solution::findMin(const vector<int> &A) {
    
    int len = A.size();
    
    if(len == 0) return -1;
    if(len == 1) return A[0];
    if(len == 2)
    {
        if(A[0] < A[1]) return A[0];
        else return A[1];
    }
    
    int beg = 0, end = len-1, mid;
    
    if (A[0] < A[len-1]) 
    {
        return A[0];
    }
    
    while(beg <= end && A[beg] > A[end])
    {
        mid = (beg+end)/2;
        
        if(A[mid] > A[mid+1]) return A[mid+1];
        
        else 
        {
            if(A[mid] > A[end]) beg = mid+1;
            else if(A[mid] < A[beg]) end = mid-1;
        }
    }
    
    return A[mid];
    
}
