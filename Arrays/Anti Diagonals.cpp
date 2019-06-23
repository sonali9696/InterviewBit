vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {

    int row = A.size(), col = A[0].size();
    
    int iStart=0,jStart=0;
    vector<vector<int> > v;
    
    int x=0,y=jStart;
    while(jStart != col) //i=0 left to right(starting point)
    {
        vector<int> rowV;
        x=0,y=jStart;
        while(y != -1)
        {
            rowV.push_back(A[x][y]);
            x++;
            y--;
        }
        v.push_back(rowV);
        rowV.clear();
        jStart++;
    }
    
    jStart = col-1; //col-1
    iStart=1;
    while(iStart != row)
    {
        vector<int> rowV;
        x=iStart,y=jStart;
        while(x != row)
        {
            rowV.push_back(A[x][y]);
            x++;
            y--;
        }
        v.push_back(rowV);
        rowV.clear();
        iStart++;
    }
    
    
    return v;
    
}
