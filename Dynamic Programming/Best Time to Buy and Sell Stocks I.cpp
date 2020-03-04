int Solution::maxProfit(const vector<int> &A) {
    
    const int l = A.size();
    if(l == 0) return 0;
    
    int max[l];
    max[0] = INT_MIN; //to be ignored
    max[l-1] = A[l-1];
    
    for(int i = l-2; i > 0; i--)
    {
        if(A[i] > max[i+1])
            max[i] = A[i];
        else
            max[i] = max[i+1];
    }
    
    int diff[l];
    int maxProfit = 0;
    
    for(int i=0; i < l-1; i++)
    {
        diff[i] = max[i+1] - A[i];
        if(diff[i] > 0 && maxProfit < diff[i]) maxProfit = diff[i];
    }
    
    return maxProfit;
    
}
