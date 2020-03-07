vector<vector<int> > Solution::prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    const int START = A;
    vector<vector<int> > ans;
    
    
    //Approach-2
    int N = 2*A-1; //no of rows and no of cols
    int const_left = 0, const_right = N-1;
    int half = N/2; //as N is always odd
    
    for(int i=0; i <= half; i++)
    {
        vector<int> row;
        
        if(i == 0)
        {
            for(int i=0; i<N; i++) row.push_back(A);
            ans.push_back(row);
            continue;
        }
        
        row.push_back(A);
        
        for(int j = 1; j < N-1; j++)
        {
            if(j <= const_left || j >= const_right) row.push_back(ans[i-1][j]);
            else row.push_back(ans[i-1][j] - 1);
        }
        
        row.push_back(A);
        ans.push_back(row);
        
        const_left++;
        const_right--;
    }
    
    //mirrow image around the middle row
    for(int i=half+1; i<N; i++)
    {
        vector<int> row;
        
        for(int j=0; j<N; j++) row.push_back(ans[N-1-i][j]);
        
        ans.push_back(row);
        
    }
    
    return ans;
}
