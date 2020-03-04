int memo[36];

/*int solve(int rem, int count)
{
    
    if(rem == 0)
    {
        count++;
        return count;
    }
    
    //select 1
    if(rem >= 1) solve(rem-1, count);
    
    //select 2
    if(rem >= 2) solve(rem-2, count);
}*/


int Solution::climbStairs(int A) {
    memset(memo, sizeof(memo), 0);
    
    memo[0] = 1;
    memo[1] = 1;
    
    for(int i=2; i<=A; i++)
    {
        memo[i] = memo[i-1] + memo[i-2];
    }
    
    
    return memo[A];
}
