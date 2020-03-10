int Solution::bulbs(vector<int> &A) {
    const int l = A.size();
    if(l == 0) return 0;
    
    int ans = 0;
    int prevSwitch, currSwitch;
    
    if(A[0] == 0) 
        prevSwitch = 1;
    else
        prevSwitch = 0;
    
    for(int i=1; i<l; i++)
    {
        if(A[i] == 0)
        {
            if(prevSwitch % 2 == 0) //even
            {
                currSwitch = prevSwitch + 1;
            }
            else //odd
            {
                currSwitch = prevSwitch;
            }
        }
        else
        {
            if(prevSwitch % 2 == 0) //even
            {
                currSwitch = prevSwitch;
            }
            else //odd
            {
                currSwitch = prevSwitch + 1;
            }
        }
        
        prevSwitch = currSwitch;
    }
    
    ans = prevSwitch;
    
    /*for(int i=0; i<l; i++)
    {
        if(A[i] == 0)
        {
            for(int j=i; j<l; j++) 
            {
                if(A[j] == 0) A[j] = 1;
                else A[j] = 0;
            }
            ans++;
        }
    }*/
    
    return ans;
}
