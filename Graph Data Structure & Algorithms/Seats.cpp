int Solution::seats(string A) {
    
    long long int ans = 0;
    
    int n = A.length();
    if(n == 0 || n == 1) return ans;
    
    vector<int> ppl;
    for(int i=0; i<n; i++)
    {
        if(A[i] == 'x') ppl.push_back(i);
    }
    int n2 = ppl.size(), median;
    if(n2 == 0 || n2 == 1) return 0;
    if(n2 % 2 == 0) //even
        median = ppl[n2/2 - 1];
    else
        median = ppl[n2/2];
        
    int left = 1, right = 1;
    for(int i=0; i<n2; i++)
    {
        if(ppl[i] < median) 
        {
            ans += (median - ppl[i] - left);
            left++;
        }
        else if(ppl[i] > median)
        {
            ans += (ppl[i]-(median+right));
            right++;
        }
    }
    
    return ans % 10000003;
    
}
