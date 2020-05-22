int Solution::numTrees(int A) {
    const int n = A;
    int dp[n]; //index = number of nodes, dp[i] = number of trees for A=i
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    int l, r, curr_sum;
    
    for(int i=3; i<=A; i++)
    {
        l = 0, r = i-l-1, curr_sum = 0; //number of nodes in left and right subtree
        while(r >= 0)
        {
            curr_sum += dp[l] * dp[r];
            r--;
            l++;
        }
        dp[i] = curr_sum;
    }
    
    return dp[n];
}
