int Solution::canJump(vector<int> &A) {
    
    int n = A.size();
    int dp[n];
    memset(dp,0,sizeof(dp));
    
    dp[n-1] = 1;
    if(n < 2) return 1;
    
    int minIndexPossible = n-1;
    
    for(int i = n-1; i >= 0; i--)
    {
        if(i+A[i] >= minIndexPossible) 
        {
            dp[i] = 1;
            minIndexPossible = i;
        }
        
        /*
        int count = A[i];
        
        
        while(count != 0)
        {
            if(i+count < n && dp[i+count] == 1)
            {
                dp[i] = 1;
                break;
            }
            count--;
        }*/
    }
    
    return dp[0];
}
