vector<int> Solution::wave(vector<int> &A) {
    
    int len = A.size();
    if(len == 0 || len == 1) return A;
    
    sort(A.begin(), A.end());
    
    for (int i = 0; i<len; i = i+2)
    {
        if(i+1 < A.size())
        {
            int temp = A[i+1];
            A[i+1] = A[i];
            A[i] = temp;
        }
        else break; //last number in odd number of elements
    }
    
    return A;
    
    
}
