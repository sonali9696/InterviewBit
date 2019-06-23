int Solution::findCount(const vector<int> &A, int B) {
    
    int len = A.size();
    int begin = 0, end = len-1;
    int mid;
    
    while(begin <= end)
    {
        mid = (begin+end)/2;
        
        if(A[mid] == B)
        {
            int count = 1;
            
            int pos = mid-1;
            while(pos >= 0 && A[pos] == B)
            {
                count++;
                pos--;
            }
            
            pos = mid+1;
            while(pos <= len-1 && A[pos] == B)
            {
                count++;
                pos++;
            }
            
            return count;
        }
        else if(A[mid] < B) begin = mid+1;
        else end = mid-1;
    }
    
    return 0;
}
