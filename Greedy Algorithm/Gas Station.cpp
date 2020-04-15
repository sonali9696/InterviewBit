int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int n = A.size();
    if(n == 0) return 0;
    if(n == 1)
    {
        if(A[0] >= B[0]) return 0;
        else return -1;
    }
    
    const int m = n;
    int diff[m];
    
    int total = 0;
    //int ans = -1;
    int start = -1, found = 0;
    
    for(int i=0; i<n; i++)
    {
        diff[i] = A[i] - B[i]; //gas left after reaching i+1
        total = total + diff[i];
        if(found == 0 && diff[i] >= 0)
        {
            found = 1;
            start = i;
        }
    }
    
    if(total < 0 || start == -1) return -1; //not possible to complete circle
    
    int curr_total = 0;

    for(int i = start ; i < n; i++)
    {
        curr_total += diff[i];
        if(curr_total < 0)
        {
            start = i+1;
            curr_total = 0;
        }
        
        /*if(diff[i] < 0) continue;
        int start = i, curr_total = diff[i], j;
        
        for(j = (i+1) % n; j != i; j = (j+1) % n)
        {
            curr_total += diff[j];
            if(curr_total < 0) break;
        }
        
        if(j == i)
        {
            ans = i;
            break;
        }*/
    }
    
    
    return start;
    
}
