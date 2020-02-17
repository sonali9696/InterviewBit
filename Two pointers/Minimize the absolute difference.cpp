int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int l1 = A.size(), l2 = B.size(), l3 = C.size();
    int p = 0, q = 0 , r = 0;
    long long int ans = INT_MAX;
    
    while(p < l1 && q < l2 && r < l3)
    {
        char array;
        
        long long int min = A[p];
        array = 'a';
        if(min > B[q]) 
        {
            min = B[q];
            array = 'b';
        }
        if(min > C[r]) 
        {
            min = C[r];
            array = 'c';
        }
        
        long long int max = A[p];
        if(max < B[q]) max = B[q];
        if(max < C[r]) max = C[r];
        
        if(abs(max - min) < ans) ans = abs(max-min);
     
        if(array == 'a') p++;
        else if(array == 'b') q++;
        else if(array == 'c') r++;
    }
    
    return ans;
}
