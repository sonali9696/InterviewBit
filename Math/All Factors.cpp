vector<int> Solution::allFactors(int A) {
    
    
    vector <int> ans1;
    vector <int> ans2;
    
    if(A <= 1) 
    {
        ans1.push_back(A);
        return ans1;
    }
    
    for(int i=1; i<=sqrt(A);i ++)
    {
        if(A % i == 0)
        {
            ans1.push_back(i);
            if(A/i != i) ans2.push_back(A/i);
        }
    }
    
    reverse(ans2.begin(),ans2.end());
    
    ans1.insert(ans1.end(), ans2.begin(), ans2.end());
    
    return ans1;
}
