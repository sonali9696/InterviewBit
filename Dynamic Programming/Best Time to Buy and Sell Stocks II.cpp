int Solution::maxProfit(const vector<int> &a) {
    
    int l = a.size();
    if(l == 0 || l == 1) return 0;
    int p = 0, prev = a[0];
    
    for(int i=1; i<l; i++)
    {
        if(a[i] > prev)
        {
            p += (a[i]-prev);
            prev = a[i];
        }
        else if(a[i] < prev)
        {
            prev = a[i];
        }
    }
    
   
    return p;
}
