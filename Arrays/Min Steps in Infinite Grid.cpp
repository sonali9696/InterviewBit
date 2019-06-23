int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int len = A.size();
    int result = 0;
    for(int i=0; i<len-1; i++)
    {
        int curr_result = 0;
        if(A[i+1] == A[i]) 
        {
            //diagonal move
            curr_result = abs(B[i+1] - B[i]);
            result = result+curr_result;
            continue;
        }
        if(B[i+1] == B[i]) 
        {
            //diagonal move
            curr_result = abs(A[i+1] - A[i]);
            result = result+curr_result;
            continue;
        }
        if( abs(A[i+1] - A[i]) <= abs(B[i+1] - B[i])) 
        {
            //move diagonally till row is same
            curr_result = abs(A[i+1] - A[i]);
            int new_col = 0;
            if(B[i+1] > B[i]) new_col = B[i] + curr_result;
            else new_col = B[i] - curr_result;
            
            curr_result = curr_result + abs(new_col - B[i+1]);
            
        }
        else
        {
            //move diagonally till col is same
            curr_result = abs(B[i+1] - B[i]);
            
            int new_row = 0;
            if(A[i+1] > A[i]) new_row = A[i] + curr_result;
            else new_row = A[i] - curr_result;
            
            curr_result = curr_result + abs(new_row - A[i+1]);
        }
        result = result+curr_result;
    }
    
    return result;
}


