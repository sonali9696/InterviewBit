int Solution::titleToNumber(string A) {
    int l = A.length(),ans=0;
    //BAA = 26*26*(2) + 26*(1) + 1
    int n = l-1,prod=1, index=0;
    
    while(index < l)
    {
        prod=1;
        for(int i=1; i<=n; i++) prod *= 26;
        prod *= (A[index]-'A' + 1);
        ans += prod;
        index++;
        n--;
    }
    
    //ans += (A[l-1]-'A' + 1); //for rightmost character
    return ans;
}
