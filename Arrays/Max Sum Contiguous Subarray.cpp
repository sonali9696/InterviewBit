int Solution::maxSubArray(const vector<int> &A) {
    int l = A.size();
    
    
    int curr_max = A[0];
    int max_till_now = A[0];
    for(int i=1; i<l; i++)
    {
        if(max_till_now + A[i] < A[i]) max_till_now = A[i];
        else max_till_now = max_till_now + A[i];
        
        curr_max = (curr_max > max_till_now)?curr_max:max_till_now;
    }
    
    return curr_max;
}

