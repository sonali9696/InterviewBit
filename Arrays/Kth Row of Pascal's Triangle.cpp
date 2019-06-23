vector<int> Solution::getRow(int A) {

    //vector<vector<int> > tri;
    vector <int> previous;
    vector <int> ans;
    int col = 0;
    
    //note that: 
    //1. the numbers are repeated around the middle (mirror image) so store only half the numbers and mid number + 1
    //2. you only need to store the previous row (k-1) to return kth row so half there as well.
    //using both 1 and 2 will give a better optimal solution than the website
    ans.push_back(1);
    previous.push_back(1);
    
    if(A == 0)
    {
        return ans;
    }
    else if (A == 1)
    {
        ans.push_back(1);
        return ans;
    }
    previous.push_back(1); //as for A=2, previous is 1 1
    
    for(int row=2; row<=A; row++)
    {
        vector <int> current;
        current.push_back(1);
        for(int col=1; col < row; col++) //as last col is 1 always
        {
            current.push_back(previous[col-1]+previous[col]);
        }
        current.push_back(1);
        previous = current;
        if(row == A) ans=current;
    }
    
    return ans;
    
    /*for(int i=0; i<=A; i++)
    {
        
        tri.push_back(vector<int>());
        tri[i].push_back(1);
        col = 1;
        
        
        if(i != A)
        {
            while(i>=1 && col <= (int)(A/2) + 1)
            {
                tri[i].push_back(tri[i-1][col-1] + tri[i-1][col]);
                col++;
            }
        }
        else if(i == A)
        {
            while(i>=1 && col <= (int)(A/2) + 1)
            {
                ans.push_back(tri[i-1][col-1] + tri[i-1][col]);
                col++;
            }
            break;
        }
        
    }
    
    int j;
    for(j = (int)(A/2)+2; j<=A; j++)
    {
        ans.push_back(ans[A-j]);
    }
    
    return ans;*/
}
