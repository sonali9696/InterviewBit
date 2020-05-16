/*void traverse(int total, int curr_row, int curr_col, vector<vector<int> > &A, 
            int tot_row, int tot_col, int &min_total)
{
    
    total = total + A[curr_row][curr_col];
    
    if(curr_row == tot_row && curr_col == tot_col) 
    {
        if(total < min_total) min_total = total;
        return;
    }
    if(curr_row == tot_row && curr_col != tot_col) 
    {
        while(curr_col != tot_col)
        {
            curr_col++;
            total += A[curr_row][curr_col];
        }
        if(total < min_total) min_total = total;
        return;
    }
    if(curr_row != tot_row && curr_col == tot_col) 
    {
        while(curr_row != tot_row)
        {
            curr_row++;
            total += A[curr_row][curr_col];
        }
        if(total < min_total) min_total = total;
        return;
    }
    
    traverse(total, curr_row+1, curr_col, A, tot_row, tot_col, min_total);
    traverse(total, curr_row, curr_col+1, A, tot_row, tot_col, min_total);
}*/

int Solution::minPathSum(vector<vector<int> > &A) {
    
    int c = A[0].size(), r = A.size();
    if(c == 0 || r == 0) return 0;
    if(c == 1 && r == 1) return A[0][0];
    
    vector<vector<int> > min(r, vector<int> (c,INT_MAX));
    
    min[0][0] = A[0][0];
    int cr = 0, cc = 0;
    
    for(int i=1; i<r; i++) min[i][0] = min[i-1][0] + A[i][0];
    for(int i=1; i<c; i++) min[0][i] = min[0][i-1] + A[0][i];
    
    for(int i=1; i<r; i++)
    {
        for(int j=1; j<c; j++)
        {
            min[i][j] = (min[i-1][j] < min[i][j-1])?min[i-1][j]:min[i][j-1];
            min[i][j] += A[i][j];
        }
    }
    
    return min[r-1][c-1];
}
