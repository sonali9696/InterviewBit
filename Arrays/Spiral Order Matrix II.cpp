vector<vector<int> > Solution::generateMatrix(int A) {

    vector<vector<int> > v;
    
    for(int i=0; i<A; i++)
    {
        vector<int> rowV;
        for(int j=0; j<A; j++)
        {
            rowV.push_back(0);
        }
        v.push_back(rowV);
    }
    
    int count = 2,i=0,j=0;
    const int N = A*A;
    v[0][0] = 1;
    while(count != N+1)
    {
        while(j+1 < A && v[i][j+1] == 0)
        {
            v[i][++j] = count;
            count++;
        }
        if(count == N+1) break;
        
        while(i+1 < A && v[i + 1][j] == 0)
        {
            v[++i][j] = count;
            count++;
        }
        if(count == N+1) break;
        
        while(j-1 >= 0 && v[i][j-1] == 0)
        {
            v[i][--j] = count;
            count++;
        }
        if(count == N+1) break;
        
        while(i-1 >= 0 && v[i - 1][j] == 0)
        {
            v[--i][j] = count;
            count++;
        }
        
    }
    
    return v;
}
