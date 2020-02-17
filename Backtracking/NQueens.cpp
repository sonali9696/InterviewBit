 void compute (int row, vector<vector<string> > &ans, vector<string> temp,
        int A, vector<vector<int> > matrix)
 {
    //cout<<"function started at row="<<row<<endl; 
    
    if(row >= A) return;
    
    for(int col = 0; col < A; col++)
    {
        //cout<<"row="<<row<<endl;
        //cout<<"col="<<col<<endl;
        //check if it is allowed
        
        //check if the row above has it
        int r = row-1, flag = 0;
        while(r >= 0)
        {
            if(matrix[r][col] == 1)
            {
                flag = 1;
                break;
            }
            r--;
        }
        
        if(flag == 1) 
        {
            //cout<<"Q in same col, above row at r="<<r<<endl;
            if(col == A-1) 
            {
                temp.clear();
                return;
            }
            continue;
        }
        
        //check if left diagonal has it
        r = row-1;
        int c = col-1;
        while(r >= 0 && c >= 0)
        {
            if(matrix[r][c] == 1)
            {
                flag = 1;
                break;
            }
            r--;
            c--;
        }
        if(flag == 1) 
        {
            //cout<<"Q in left diag, r="<<r<<" and c="<<c<<endl;
            if(col == A-1) 
            {
                temp.clear();
                return;
            }
            continue;
        }
        
        //check if rigt diagonal has it
        r = row-1, c = col+1;
        while(r >= 0 && c < A)
        {
            if(matrix[r][c] == 1)
            {
                flag = 1;
                break;
            }
            r--;
            c++;
        }
        if(flag == 1) 
        {
            //cout<<"Q in right diag, r="<<r<<" and c="<<c<<endl;
            if(col == A-1) 
            {
                temp.clear();
                return;
            }
            continue;
        }
        
        //else fits!
        matrix[row][col] = 1;
        
        string entry; 
        for(int i=0; i<A;i++)
        {
            if(i != col) entry = entry + ".";
            else entry = entry + "Q";
        }
        temp.push_back(entry);
        
        //cout<<"entry fits as "<<entry<<endl;
        
        //push to ans if final
        if(row == A-1)
        {
            cout<<"reached final"<<endl;
            ans.push_back(temp);
            return; //as only 1 column possible when reached last row
        }
        
        compute(row+1, ans, temp, A, matrix);
        
        //reset for next possible column
        matrix[row][col] = 0;
        temp.pop_back();
    }
    
 }

vector<vector<string> > Solution::solveNQueens(int A) {
    
    vector<vector<string> > ans;
    vector<string> temp;
    vector<vector<int> > matrix;
    
    for(int i=0; i<A; i++)
    {
        vector<int> matTemp;
        for(int j=0; j<A; j++)
        {
            matTemp.push_back(0);
        }
        matrix.push_back(matTemp);
    }
   
    compute(0, ans, temp, A, matrix);
    
    return ans;
}
