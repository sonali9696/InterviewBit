int Solution::singleNumber(const vector<int> &A) {
    
    int len = A.size();
    int result = A[0];
    for(int i = 1; i < len; i++)
    {
        result = result ^ A[i];
    }
    
    return result;
}
