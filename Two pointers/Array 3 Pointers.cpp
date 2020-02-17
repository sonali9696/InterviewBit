int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    
    int l1 = A.size(), l2 = B.size(), l3 = C.size();
    int p = 0, q = 0 , r = 0;
    long long int ans = INT_MAX;
    while(p < l1 && q < l2 && r < l3)
    {
        char array;
        
        int diff1 = abs(A[p] - B[q]);
        int diff2 = abs(B[q] - C[r]);
        int diff3 = abs(C[r] - A[p]);
        
        long long int maxDiff = diff1;
        if(A[p] < B[q]) array = 'a';
        else array = 'b';
        
        if(maxDiff < diff2) 
        {
            maxDiff = diff2;
            if(B[q] < C[r]) array = 'b';
            else array = 'c';
        }
        if(maxDiff < diff3) 
        {
            maxDiff = diff3;
            if(C[r] < A[p]) array = 'c';
            else array = 'a';
        }
        
        if(ans > maxDiff) ans = maxDiff;
     
        //increase the smaller element to decrease abs difference
        if(array == 'a') p++;
        else if(array == 'b') q++;
        else if(array == 'c') r++;
    }
    
    return ans;

    
}

