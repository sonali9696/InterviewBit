vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int r = 0, count = 0, c = 0;
    int C = A[0].size(), R=A.size(); 
    
    //cout<<R<<"and"<<C;
    
    vector<int> result;
    result.push_back(A[0][0]);
    count++;
    
    int srow = 0, erow = R-1, scol = 0, ecol = C-1, flag = 0; 
    
    while(count != R*C)
    {
        flag = 0;
        while(c+1<=ecol) 
        {
            c++;
            result.push_back(A[r][c]);
            count++;
            if(count == R*C)
            {
                flag = 1;
                break;
            }
        }
        srow++;
        
        if(flag == 1) break;    
        
        flag = 0;
        while(r+1 <= erow)
        {
            r++;
            result.push_back(A[r][c]);
            count++;
            if(count == R*C)
            {
                flag = 1;
                break;
            }
        }
        ecol--;
        if(flag == 1) break;
        
        flag = 0;
        while(c-1 >= scol)
        {
            c--;
            result.push_back(A[r][c]);
            count++;
            if(count == R*C)
            {
                flag = 1;
                break;
            }
        }
        erow--;
        if(flag == 1) break;
        
        flag = 0;
        while(r-1 >= srow)
        {
            r--;
            result.push_back(A[r][c]);
            count++;
            if(count == R*C)
            {
                flag = 1;
                break;
            }
        }
        scol++;
        if(flag == 1) break;
        
    }
    
    return result;
}
