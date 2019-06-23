int Solution::trailingZeroes(int A) {
    // 2*5 = 10; no of 5's always lesser than no of 2s so just count 5s.
    //25 = two 5's so multiples of 5 to be considered too
    //5^2, 5^3, so on --> log(5) is the max power of 5 possible
    //25's multiples all have an extra 5 i.e. 25,50,75
    //125's multiples have 2 extra 5's so on but
    //250 is multiple of 125,25,5 but it should have 3 5s only.
    //thus just count once for 5,25,125 etc. 
    //Hence 250 is multiple of 5(1 '5'), multiple of 25(2 '5'), multiple of 25(3 '5')
    //hence ans = n/5 + n/25 + n/125...so on
    
    if(A < 5) return 0;
    
    int maxPower = (int)(log(A)/log(5));
    
    int ans=0;
    while(maxPower != 0)
    {
        ans += A/pow(5,maxPower);
        maxPower--;
    }
    
    return ans;
}
