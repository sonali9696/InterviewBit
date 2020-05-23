int Solution::lis(const vector<int> &A) {
    
    const int n = A.size();
    int dp[n], longest = 1;
    dp[0] = 1;
    
    for(int i=0; i<n; i++) dp[i] = 1;
    
    if(n <= 2) return n;
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[j] < A[i])
            {
                if(dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    if(dp[i] > longest) 
                    {
                        longest = dp[i];
                    }
                }
            }
        }
    }
    
    return longest;
}
