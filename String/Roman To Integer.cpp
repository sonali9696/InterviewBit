int Solution::romanToInt(string A) {
    
    map<char, int> m;
    
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    int ans = 0;
    int l = A.size();
    int i=1;
    
    while(i<l)
    {
        if(m[A[i]] <= m[A[i-1]]) //eg: VI for 6 = 5+1
        {
            ans += m[A[i-1]];
        }
        else //eg: IV = -1+5 = 4
        {
            ans -= m[A[i-1]];
        }
        
        i++;
    }
    
    //last position
    ans += m[A[l-1]];
    
    return ans;
    
    
}
