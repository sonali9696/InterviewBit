int Solution::gcd(int A, int B) {
    
    if(A == 0 && B == 0) return 0;
    else if(A == 0 && B != 0) return B;
    else if(A != 0 && B == 0) return A;
    
    int high,low;
    
    if(A >= B) 
    {
        high = A;
        low = B;
    }
    else
    {
        high = B;
        low = A;
    }
    
    int rem = high % low;
    while(rem != 0)
    {
        high = low;
        low = rem;
        rem = high % low;
    }
    
    return low;
    
}
