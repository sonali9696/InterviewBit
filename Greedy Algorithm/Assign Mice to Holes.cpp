int Solution::mice(vector<int> &A, vector<int> &B) {
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int maxTime = 0;
    int l = A.size();
    
    for(int i = 0; i < l; i++)
    {
        int diff = abs(A[i] - B[i]);
        if(diff > maxTime) maxTime = diff;
    }
    
    return maxTime;
}
