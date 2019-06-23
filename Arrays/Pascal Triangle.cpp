vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > ans;
    int col = 0;
    
    for(int i=0; i<A; i++)
    {
        ans.push_back(vector<int>());
        
        col = 0;
        ans[i].push_back(1);
        col = 1;
        
        while(i >= 2 && col < i) //As max value of col in ith row is i
        {
            ans[i].push_back(ans[i-1][col-1] + ans[i-1][col]);
            col++;
        }
        
        if(i > 0) ans[i].push_back(1);
    }
    
    return ans;
}
