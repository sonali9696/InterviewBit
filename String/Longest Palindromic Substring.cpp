string Solution::longestPalindrome(string A) {
    int l = A.size();
    
    if(l == 1) return A;
    else if(l == 2)
    {
        if(A[0] == A[1]) return A;
        else
        {
            string ans1 = "";
            ans1 += A[0];
            return ans1;
        }
    }
    
    
    string ans = "";
    ans += A[0];
    
    int max = 1;
    int i,j, len;
    
    
    
    for(int p=1; p<l-1;p++)
    {
        //odd
        i = p - 1, j = p+1, len=1;
        
        
        while(i>=0)
        {
            if(A[i] == A[j]) len += 2;
            else break;
            
            
            i--;
            j++;
        }
        
        if(len > max)
        {
            max = len;
            ans = "";
            for(int k = i+1; k<= j-1; k++)
            {
                ans += A[k];
            }
        }
        
        //even
        
        if(A[p] == A[p+1])
        {
            len = 2;
            i = p-1; j = p+2;
            
            while(i>=0)
            {
                if(A[i] == A[j]) len += 2;
                else break;
                
                i--;
                j++;
            }
        
            if(len > max)
            {
                max = len;
                ans = "";
                for(int k = i+1; k<= j-1; k++)
                {
                    ans += A[k];
                }
            }
        }
        
    }
    
    return ans;
}
